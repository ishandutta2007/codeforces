#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=101000;
int l[N],r[N],l2[N],r2[N],f[N],col[N],chs[N],vis[N];
int n,T,t,m,cnt,u,v;
VI e[N],vec;
vector<pair<int,PII> > Evt,evt;
multiset<int> ml,mr;
int find(int x) {
	return f[x]==x?x:f[x]=find(f[x]);
}
void dfs(int u,int c) {
	vis[u]=1; vec.pb(u); col[u]=c;
	for (auto v:e[u]) {
		if (!vis[v]) {
			dfs(v,c^1);
		} else {
			if ((col[v]^col[u])!=1) throw 1;
		}
	}
}
void add(int x1,int x2,int y1,int y2) {
//	printf("%d %d %d %d\n",x1,x2,y1,y2);
	assert(x1<=x2&&y1<=y2);
	Evt.pb(mp(x1,mp(y1,1)));
	Evt.pb(mp(x1,mp(y2,2)));
	Evt.pb(mp(x2,mp(y1,3)));
	Evt.pb(mp(x2,mp(y2,4)));
}
void build(int x1,int x2,int y1,int y2) {
	assert(x1<=x2&&y1<=y2);
//	printf("%d %d %d %d\n",x1,x2,y1,y2);
	evt.clear();
	evt.pb(mp(x1*2,mp(y1,1)));
	evt.pb(mp(x1*2,mp(y2,2)));
	evt.pb(mp(x2*2+1,mp(y1,3)));
	evt.pb(mp(x2*2+1,mp(y2,4)));
	swap(x1,y1); swap(x2,y2);
	evt.pb(mp(x1*2,mp(y1,1)));
	evt.pb(mp(x1*2,mp(y2,2)));
	evt.pb(mp(x2*2+1,mp(y1,3)));
	evt.pb(mp(x2*2+1,mp(y2,4)));
	sort(all(evt));
	ml.clear(); mr.clear();
	rep(i,0,SZ(evt)) {
		if (evt[i].se.se==1) ml.insert(evt[i].se.fi);
		if (evt[i].se.se==2) mr.insert(evt[i].se.fi);
		if (evt[i].se.se==3) ml.erase(ml.find(evt[i].se.fi));
		if (evt[i].se.se==4) mr.erase(mr.find(evt[i].se.fi));
		if (i!=SZ(evt)-1&&evt[i].fi!=evt[i+1].fi) {
			if (SZ(ml)) add(evt[i].fi,evt[i+1].fi,*ml.begin(),*mr.rbegin());
		}
	}
}
void gao(int x,int y) {
	puts("POSSIBLE");
	printf("%d %d\n",x,y);
	rep(i,1,n+1) if (find(i)==i) {
		if (l[i]<=x&&x<=r[i]&&l2[i]<=y&&y<=r2[i]) chs[i]=0; else chs[i]=1;
	}
	rep(i,1,n+1) putchar('1'+(chs[find(i)]^col[i]));
	
}
bool check(int x1,int x2,int y1,int y2) {
	if (x1>x2||y1>y2) return 0;
	if (x2+y2<t||x1+y1>T) return 0;
//	printf("Check %d %d %d %d\n",x1,x2,y1,y2);
	if (t<=x1+y1&&x2+y2<=T) {
		gao(x1,y1);
		return 1;
	}
	if (x1+y1<t&&x2+y2<=T) {
		gao(x2,y2);
		return 1;
	}
	if (t<=x1+y1&&T<x2+y2) {
		gao(x1,y1);
		return 1;
	}
	if (x1+y1<t&&T<x2+y2) {
		if (T-x1<=y2&&T-x1>=y1) gao(x1,T-x1);
		else if (t-x1<=y2&&t-x1>=y1) gao(x1,t-x1);
		else if (T-y1<=x2&&T-y1>=x1) gao(T-y1,y1);
		else if (t-y1<=x2&&t-y1>=x1) gao(t-y1,y1);
		else if (T-x2<=y2&&T-x2>=y1) gao(x2,T-x2);
		else if (t-x2<=y2&&t-x2>=y1) gao(x2,t-x2);
		else if (T-y2<=x2&&T-y2>=x1) gao(T-y2,y2);
		else if (t-y2<=x2&&t-y2>=x1) gao(t-y2,y2);
		return 1;
	}	
}
bool cmp(pair<int,PII> a,pair<int,PII> b) {
	return mp(a.fi,mp(-a.se.se,a.se.fi))<mp(b.fi,mp(-b.se.se,b.se.fi));
}
int main() {
//	freopen("in.txt","r",stdin);
	scanf("%d%d",&t,&T);
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) scanf("%d%d",l+i,r+i),l2[i]=0,r2[i]=1000000001;
	rep(i,1,n+1) f[i]=i;
	rep(i,0,m) {
		scanf("%d%d",&u,&v);
		f[find(u)]=find(v);
		e[u].pb(v); e[v].pb(u);
	}
	rep(i,1,n+1) if (!vis[i]) {
		vec.clear();
		try {
			dfs(i,0);
		} catch(int e) {
			puts("IMPOSSIBLE");
			return 0;
		}
		int pl=0,pr=1000000001,ql=0,qr=1000000001;
		for (auto j:vec) {
			if (col[j]==0) pl=max(pl,l[j]),pr=min(pr,r[j]);
			else ql=max(ql,l[j]),qr=min(qr,r[j]);
		}
		if (pl>pr||ql>qr) {
			puts("IMPOSSIBLE");
			return 0;
		}
		int p=find(i);
		l[p]=pl, r[p]=pr; l2[p]=ql,r2[p]=qr;
	}
	rep(i,1,n+1) if (find(i)==i) {
//		printf("Gao %d\n",i);
		build(l[i],r[i],l2[i],r2[i]);
		cnt++;
	}
	evt=Evt;
	sort(all(evt),cmp);
	ml.clear(); mr.clear();
	rep(i,0,SZ(evt)) {
		if (evt[i].se.se==1) ml.insert(evt[i].se.fi);
		if (evt[i].se.se==2) mr.insert(evt[i].se.fi);
		if (evt[i].se.se==3) ml.erase(ml.find(evt[i].se.fi));
		if (evt[i].se.se==4) mr.erase(mr.find(evt[i].se.fi));
		if (i!=SZ(evt)-1&&evt[i].fi!=evt[i+1].fi&&SZ(ml)==cnt) {
			if (check((evt[i].fi+1)/2,(evt[i+1].fi+1)/2-1,*ml.rbegin(),*mr.begin())) {
				return 0;
			}
		}
	}
	puts("IMPOSSIBLE");
}