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

const int N=301000;
int n,x[N];
ll ret;
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",x+i); sort(x,x+n);
	rep(i,1,n) {
		int y=x[i]-x[i-1];
		ret=(ret+y*(powmod(2,i)-1)%mod*(powmod(2,n-i)-1))%mod;
	}
	printf("%lld\n",ret);
}