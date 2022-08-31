#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=401000;
int n,m,cnt;
int a[N],pv[N],vis[N],T;
int minadj[N];
VI adj[N];
set<PII> hs;

void check(int x,int y) {
	if (x>y) swap(x,y);
	pv[x]=y; pv[y]=x;
	T++;
	VI chk;
	for (auto p:adj[x]) if (vis[p]!=T) {
		vis[p]=T;
		chk.pb(p);
	}
	for (auto p:adj[y]) if (vis[p]!=T) {
		vis[p]=T;
		chk.pb(p);
	}
	if (vis[x]!=T) chk.pb(x),vis[x]=T;
	if (vis[y]!=T) chk.pb(y),vis[y]=T;
	int cc=cnt;
	for (auto p:chk) {
		cc-=minadj[p]>p;
		int minv=n*m;
		for (auto q:adj[p])
			minv=min(minv,pv[q]);
		cc+=minv>pv[p];
	}
	pv[x]=x; pv[y]=y;
	if (cc==1) hs.insert({x,y});
}

int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,n*m) {
		scanf("%d",&a[i]),--a[i];
		pv[i]=i;
	}
	if (n*m==1) {
		puts("0");
		return 0;
	}
	rep(i,0,n*m) {
		int x=i/m,y=i%m;
		if (x>0) adj[a[i]].pb(a[i-m]);
		if (x+1<n) adj[a[i]].pb(a[i+m]);
		if (y>0) adj[a[i]].pb(a[i-1]);
		if (y+1<m) adj[a[i]].pb(a[i+1]);
	}
	int val=n*m;
	rep(i,0,n*m) {
		minadj[i]=*min_element(all(adj[i]));
		cnt+=minadj[i]>i;
		if (i!=0&&minadj[i]>i) {
			val=min(val,i);
		}
	}
	if (cnt==1) {
		puts("0");
		return 0;
	}
	rep(i,val+1,n*m) check(val,i);
	for (auto p:adj[val]) 
		rep(i,0,p) check(i,p);
	int ans=SZ(hs);
	if (ans==0) {
		puts("2");
	} else {
		printf("1 %d\n",ans);
	}
}