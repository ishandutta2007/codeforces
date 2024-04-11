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

int n;
int vv[1010][20][3];
int main() {
	scanf("%d",&n);
	rep(i,0,10) {
		VI v;
		rep(j,1,n+1) if ((j&(1<<i))==0) v.pb(j);
		if (v.empty()) {
			rep(j,1,n+1) vv[j][i][0]=1<<30;
			continue;
		}
		printf("%d\n",SZ(v));
		for (auto c:v) printf("%d ",c); puts("");
		fflush(stdout);
		rep(j,1,n+1) scanf("%d",&vv[j][i][0]);
	}
	rep(i,0,10) {
		VI v;
		rep(j,1,n+1) if ((j&(1<<i))) v.pb(j);
		if (v.empty()) {
			rep(j,1,n+1) vv[j][i][1]=1<<30;
			continue;
		}
		printf("%d\n",SZ(v));
		for (auto c:v) printf("%d ",c); puts("");
		fflush(stdout);
		rep(j,1,n+1) scanf("%d",&vv[j][i][1]);
	}
	puts("-1");
	rep(i,1,n+1) {
		int mv=1<<30;
		rep(j,0,10) mv=min(mv,vv[i][j][1-((i>>j)&1)]);
		printf("%d ",mv);
	}
	puts("");
	fflush(stdout);
}