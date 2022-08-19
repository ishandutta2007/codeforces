#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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
// head

#define y1 afasdfads
//const int N=16;
//int a[110][110];
int _,x1,y1,x2,y2,k;
ll cret,inv=powmod(2,mod-2);
ll solve(ll x,ll y,ll k) {
	--k;
	if (x<=0||y<=0) return 0;
	vector<ll> dx,dy;
	dx.pb(x); dy.pb(y);
	while (x) x-=x&-x,dx.pb(x);
	while (y) y-=y&-y,dy.pb(y);
	ll ret=0;
	rep(i,0,SZ(dx)-1) rep(j,0,SZ(dy)-1) {
		int v=max(__builtin_ctzll(dx[i]),__builtin_ctzll(dy[j]));
		ll prex=((dx[i+1]^dy[j+1])>>v)<<v;
		ll cnt=((dx[i]-dx[i+1])*(dy[j]-dy[j+1])>>v)%mod;
		ll b=prex,e=min(prex+(1<<v)-1,k);
		if (b<=e) ret=(ret+(b+e+2)%mod*(e-b+1)%mod*inv%mod*cnt)%mod;
	}
	return ret;
}
int main() {
/*	rep(i,1,N) {
		rep(j,1,N) {
			set<int> s;
			rep(k,1,i) s.insert(a[k][j]);
			rep(k,1,j) s.insert(a[i][k]); a[i][j]=1;
			while (s.count(a[i][j])) a[i][j]++;
			printf("%d ",a[i][j]);
		}
		puts("");
	}*/
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&k);
		cret=solve(x2,y2,k)+solve(x1-1,y1-1,k)-solve(x2,y1-1,k)-solve(x1-1,y2,k);
		cret%=mod;
		if (cret<0) cret+=mod;
		printf("%lld\n",cret);
	}
}