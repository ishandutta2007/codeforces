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
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=151000;
int ans,n,x,a[N],pw[N];
map<int,pair<VI,VI>> v;


ll count(VI a, VI b, int x, int d) {
	if (a.empty()||b.empty()) return 0;
	if (d==-1) {
		return (pw[SZ(a)]-1)*(pw[SZ(b)]-1)%mod;
	} else {
		int w=(x>>d)&1;
		VI a0,a1,b0,b1;
		for (auto x:a) if ((x>>d)&1) a1.pb(x); else a0.pb(x);
		for (auto x:b) if ((x>>d)&1) b1.pb(x); else b0.pb(x);
		if (w==0) {
			return (count(a0,b0,x,d-1)+count(a1,b1,x,d-1))%mod;
		} else {
			ll fa=count(a0,b1,x,d-1)+pw[SZ(a0)]+pw[SZ(b1)]-1,fb=count(a1,b0,x,d-1)+pw[SZ(a1)]+pw[SZ(b0)]-1;
			return (fa*fb-pw[SZ(a)]-pw[SZ(b)]+1)%mod;
		}
	}
}

int main() {
	scanf("%d%d",&n,&x);
	pw[0]=1;
	rep(i,1,n+1) pw[i]=pw[i-1]*2%mod;
	if (x!=0) {
		int d=0;
		int y=x;
		while (y) y/=2,d+=1;
		rep(i,0,n) {
			scanf("%d",a+i);
			if ((a[i]>>(d-1)&1)) v[a[i]>>d].se.pb(a[i]);
			else v[a[i]>>d].fi.pb(a[i]);
		}
		for (auto xx:v) {
			VI a=xx.se.fi,b=xx.se.se;
			ans=(ans+powmod(2,SZ(a))-1+powmod(2,SZ(b))-1)%mod;
			ans=(ans+count(a,b,x,d))%mod;
		}
	} else {
		rep(i,0,n) {
			scanf("%d",a+i);
			v[a[i]].fi.pb(a[i]);
		}
		for (auto xx:v) {
			VI a=xx.se.fi,b=xx.se.se;
			ans=(ans+powmod(2,SZ(a))-1+powmod(2,SZ(b))-1)%mod;
		}
	}
	if (ans<0) ans+=mod;
	printf("%d\n",ans);
}