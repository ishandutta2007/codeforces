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

ll dp[20][20][20][2];
int _;
char s[20];
inline bool gao(int x,int y,int z,int val,int p) {
	if (p>y) return 0;
	if (y>=4*(x+1)&&!val) return 0;
	if (4*x<=y&&y<4*(x+1)) {
		int r=(p>>(y-4*x))&1;
		if (r==0) return 0;
	}
	return 1;
}
ll calc(int x,int y,int z,int val) { // x bit supposed max current max valid=0
	if (x==-1) { return y==z;}
	else {
		if (dp[x][y][z][val]!=-1) return dp[x][y][z][val];
		ll &r=dp[x][y][z][val]; r=0;
		rep(i,0,y+1) if (gao(x,y,z,val,i)) {
			r+=calc(x-1,y,max(z,i),val|(4*x<=y&&y<4*(x+1)));
		}
		return r;
	}
}
ll fuck(char *s) {
	int n=strlen(s);
	ll t=0;
	rep(i,0,n) {
		t=t*16;
		if (s[i]<='9') t+=s[i]-'0';
		else t+=s[i]-'a'+10;
	}
	return t;
}
ll solve(ll x) { // zero ????
	VI d;
	while (x) d.pb(x&15),x>>=4;
	ll ret=0;
	rep(i,0,SZ(d)-1) {
		rep(y,0,16) {
			rep(j,1,16) if (gao(i,y,0,0,j)) {
				ret+=calc(i-1,y,j,(4*i<=y&&y<4*(i+1)));
			}
		}
	}
	rep(y,0,16) {
		bool val=0; int cm=0;
		per(i,0,SZ(d)) {
			rep(j,i==(SZ(d)-1)?1:0,d[i]) if (gao(i,y,cm,val,j)){
				ret+=calc(i-1,y,max(cm,j),val|(4*i<=y&&y<4*(i+1)));
			}
			if (!gao(i,y,cm,val,d[i])) break;
			cm=max(cm,d[i]);
			val|=(4*i<=y&&y<4*(i+1));
		}
	}
	return ret;
}
int bf(int x) {
	int r=0; int y=x;
	while (x) r|=1<<(x&15),x>>=4;
	return (y^r)<y;
}
int main() {
	memset(dp,-1,sizeof(dp));
	for (scanf("%d",&_);_;_--) {
//	for (_=10000;_;_--) {
		scanf("%s",s);
		ll l=fuck(s); 
		scanf("%s",s);
		ll r=fuck(s);
//		ll l=((ll)rand()<<30)+rand(),r=((ll)rand()<<30)+rand();
		printf("%lld\n",solve(r+1)-solve(l));
	}
}