#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
//int rnd(int x) { return mrand() % x;}
typedef unsigned long long u64;
u64 rnd64() {
	return ((u64)mrand()<<32)+mrand();
}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int M=5000;
const int N=50100;

int p[N],vis[N],cnt[N],t,spt,id[N];

u64 hs[N];

struct Hash_table {
	static const int V=1000003;
	int fst[V],nxt[V];
	int ctm,ptm[V],T;
	u64 key[V];
	void init() { T=0; ctm++;}
	pair<int,bool> insert(u64 s) {
		int S=s%V;
		if (ptm[S]!=ctm) ptm[S]=ctm,fst[S]=-1;
		for (int j=fst[S];j!=-1;j=nxt[j]) if (key[j]==s) return mp(j,0);
		nxt[T]=fst[S],fst[S]=T,key[T]=s;
		return mp(T++,1);
	}
	bool query(u64 s) {
		int S=s%V;
		if (ptm[S]!=ctm) ptm[S]=ctm,fst[S]=-1;
		for (int j=fst[S];j!=-1;j=nxt[j]) if (key[j]==s) return 1;
		return 0;
	}
}Hash;
const int L=510000;
vector<PII> e[L];
VI pf[L];
ll scnt[L],ans,pans;
int n,x,pcnt[N];
PII lab[N];

void add(int u,int v,int l) {
	//printf("%d %d %d\n",u,v,l);
	//for (auto x:pf[u]) printf("%d ",x); puts("");
	//for (auto x:pf[v]) printf("%d ",x); puts("");
	e[u].pb(mp(v,l));
	e[v].pb(mp(u,l));
}

void dfs(int u,int f,int dep) {
	//if (scnt[u]) printf("%d %d\n",u,dep);
	ans+=(ll)scnt[u]*dep;
	for (auto p:e[u]) {
		if (p.fi==f) continue;
		dfs(p.fi,u,dep+p.se);
		scnt[u]+=scnt[p.fi];
	}
}

void dfs2(int u,int f) {
	ans=min(ans,pans);
	for (auto p:e[u]) {
		int v=p.fi;
		if (v==f) continue;
		pans=pans-scnt[v]*p.se+(n-scnt[v])*p.se;
		dfs2(v,u);
		pans=pans+scnt[v]*p.se-(n-scnt[v])*p.se;
	}
}

int main() {
//	scanf("%d",&n);
	for (int i=2;i<=M;i++) {
		if (!vis[i]) p[t++]=i;
		for (int j=i+i;j<=M;j+=i) vis[j]=1;
	}
//printf("faq %d\n",t);
	rep(i,0,t) hs[i]=rnd64();
	u64 hv=0;
	Hash.init();
	for (int i=1;i<=M;i++) {
		int x=i;
		for (int j=0;j<t;j++) if (x%p[j]==0) {
			while (x%p[j]==0) x/=p[j],cnt[j]++,hv+=hs[j];
		}
		//printf("ff %d %d %d\n",i,x,t);
		u64 phv=hv;
		bool fs=0;
		for (int j=0;j<=t;j++) {
			lab[j]=Hash.insert(phv);
			//rep(k,0,t) pcnt[k]=(k<j)?0:cnt[k];
			//pf[lab[j].fi]=VI(pcnt,pcnt+t);
			if (fs==1) assert(lab[j].se==0);
			//printf("%d %d %d %d %llu\n",i,j,lab[j].fi,lab[j].se,phv);
			if (lab[j].se==0&&j>0) {
				u64 qhv=phv+hs[j-1]*cnt[j-1]-hs[j-1];
				int len=1;
				while (!Hash.query(qhv)) {
					qhv-=hs[j-1];
					len++;
				}
			//	printf("faq");
				add(lab[j-1].fi,Hash.insert(qhv).fi,len);
				break;
			} else {
				if (j>0) add(lab[j-1].fi,lab[j].fi,cnt[j-1]);
			}
			if (!cnt[j]) break;
			phv-=hs[j]*cnt[j];
		}
		id[i]=lab[0].fi;
		//printf("fid %d %d\n",i,id[i]);
	}
	//puts("ff");
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d",&x);
		scnt[id[x]]++;
	}
	dfs(0,-1,0);
	pans=ans;
	//printf("%lld\n",pans);
	dfs2(0,-1);
	printf("%lld\n",ans);
}