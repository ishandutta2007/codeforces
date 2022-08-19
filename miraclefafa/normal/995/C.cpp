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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=101000;
int n,x,y,way[N];
pair<PII,int> p[N];
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d%d",&x,&y);
		p[i]=mp(mp(x,y),i);
	}
	while (1) {
		random_shuffle(p,p+n);
		ll x=0,y=0;
		rep(i,0,n) {
			ll ux=x+p[i].fi.fi,uy=y+p[i].fi.se;
			ll vx=x-p[i].fi.fi,vy=y-p[i].fi.se;
			if (ux*ux+uy*uy<vx*vx+vy*vy) {
				way[p[i].se]=1; x=ux; y=uy;
			} else {
				way[p[i].se]=-1; x=vx; y=vy;
			}
		}
		if (x*x+y*y<=2250000000000ll) {
			rep(i,0,n) printf("%d ",way[i]);
			puts("");
			return 0;
		}
	}
}