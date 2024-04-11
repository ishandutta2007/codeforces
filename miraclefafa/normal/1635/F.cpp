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

const int N=301000;

int n,q;
int x[N],w[N];
vector<PII> que[N];
vector<pair<int,ll>> p[N];
ll ret[N],c[N];
void add(int a,int b) {
	p[b].pb({a,(ll)(x[b]-x[a])*(w[b]+w[a])});
}

const ll inf=8e18;
ll query(int x) {
	ll s=inf;
	for (;x;x-=x&-x) s=min(s,c[x]);
	return s;
}
void modify(int x,ll y) {
	for (;x<=n;x+=x&-x) c[x]=min(c[x],y);
}
int main() {
	scanf("%d%d",&n,&q);
	stack<int> st;
	rep(i,1,n+1) {
		scanf("%d%d",x+i,w+i);
		while (!st.empty()&&w[i]<=w[st.top()]) {
			add(st.top(),i);
			st.pop();
		}
		if (!st.empty()) add(st.top(),i);
		st.push(i);
	}
	rep(i,0,q) {
		int x,y;
		scanf("%d%d",&x,&y);
		que[y].pb({x,i});
	}
	rep(i,1,n+1) c[i]=inf;
	rep(i,1,n+1) {
		for (auto x:p[i]) modify(n+1-x.fi,x.se);
		for (auto x:que[i]) ret[x.se]=query(n+1-x.fi);
	}
	rep(i,0,q) printf("%lld\n",ret[i]);
}