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
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=601000;
int n,k,c,c1[N],f[N],cs[N],x;
char s[N];
VI p[N];

int find(int x) { return f[x]==x?x:f[x]=find(f[x]); }

void merge(int u,int v) {
	assert(find(u)==u); assert(find(v)==v);
	f[v]=u; c1[u]+=c1[v];
}

int main() {
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	rep(i,1,n+1) s[i]^=1;
	rep(i,0,k) {
		scanf("%d",&c);
		rep(j,0,c) {
			scanf("%d",&x);
			p[x].pb(i);
		}
	}
	int ans=0;
	rep(i,0,k) c1[2*i]=0,c1[2*i+1]=1;
	rep(i,0,2*k) f[i]=i,cs[i]=0;
	rep(i,1,n+1) {
		if (p[i].empty()) {
			assert(s[i]=='0');
		} else if (SZ(p[i])==1) {
			int u=p[i][0];
			int pu=find(2*u),pv=find(2*u+1);
			if (cs[pu]==0&&cs[pv]==0) {
				ans-=min(c1[pu],c1[pv]);
				int pid=find(2*u+s[i]-'0');
				cs[pid]=1; ans+=c1[pid];
			}
		} else {
			int u=p[i][0],v=p[i][1];
			int pu=find(2*u),qu=find(2*u+1);
			int pv=find(2*v),qv=find(2*v+1);
			if (pu==pv||pu==qv) goto print;
			if (cs[pu]==0&&cs[pv]==0&&cs[qu]==0&&cs[qv]==0) {
				ans-=min(c1[pu],c1[qu]);
				ans-=min(c1[pv],c1[qv]);
				if (s[i]=='0') merge(pu,pv),merge(qu,qv);
				else merge(pu,qv),merge(qu,pv);
				ans+=min(c1[pu],c1[qu]);
			} else if (cs[pu]+cs[qu]>0&&cs[pv]+cs[qv]>0) {
				if (s[i]=='0') merge(pu,pv),merge(qu,qv);
				else merge(pu,qv),merge(qu,pv);
			} else {
				if (cs[pv]+cs[qv]>0) swap(u,v),swap(pu,pv),swap(qu,qv);
				ans-=min(c1[pv],c1[qv]);
				if (cs[pu]) ans-=c1[pu]; else ans-=c1[qu];
				if (s[i]=='0') merge(pu,pv),merge(qu,qv);
				else merge(pu,qv),merge(qu,pv);
				if (cs[pu]) ans+=c1[pu]; else ans+=c1[qu];				
			}
		}
		print:;
		printf("%d\n",ans);
	}
}