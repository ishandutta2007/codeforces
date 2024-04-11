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

int p[30][30],n,m;
bool check() {
	rep(i,0,n) {
		int cnt=0;
		rep(j,0,m) cnt+=p[i][j]!=j+1;
		if (cnt>2) return 0;
	}
	return 1;
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) rep(j,0,m) scanf("%d",&p[i][j]);
	rep(a,0,m) rep(b,a,m) {
		rep(i,0,n) swap(p[i][a],p[i][b]);
		if (check()) {
			puts("YES");
			return 0;
		}
		rep(i,0,n) swap(p[i][a],p[i][b]);
	}
	puts("NO");
}