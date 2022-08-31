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

int _,n;
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d",&n);
		VI vx,vy;
		rep(i,0,2*n) {
			int x,y;
			scanf("%d%d",&x,&y);
			if (x==0) vy.pb(abs(y)); else vx.pb(abs(x));
		}
		sort(all(vx));
		sort(all(vy)); //reverse(all(vy));
		db ans=0;
		rep(i,0,n) ans+=sqrt(1.*vx[i]*vx[i]+1.*vy[i]*vy[i]);
		printf("%.10f\n",ans);
	}
}