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

const int N=201000;
int n,m,p[N],x[N];
vector<pair<ll,ll>> evt;
int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%d",p+i);
	x[0]=-1e9;
	for (int i=1;i<=m;i++) scanf("%d",x+i);
	x[m+1]=2e9;
	sort(x,x+m+2);
	rep(i,0,n) {
		int v=100*i;
		auto t=lower_bound(x,x+m+2,v);
		if (v==*t) continue;
		auto t2=prev(t);
		int d=min((*t)-v,v-(*t2));
		int l=v-d,r=v+d;
		//printf("oo %d %d %d\n",*t2,*t,p[i]);
		evt.pb({(ll)l*3+1,p[i]});
		evt.pb({(ll)r*3-1,-p[i]});
	}
	ll ans=0,v=0;
	sort(all(evt));
	for (auto x:evt) {
		v+=x.se,ans=max(ans,v);
	}
	printf("%lld\n",ans);
}