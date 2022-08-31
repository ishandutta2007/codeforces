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

const int N=30;
int n,a[N],b[N];
PII p[N];
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i),p[i]=mp(a[i],i);
	sort(p,p+n);
	rep(i,0,n) b[p[(i+1)%n].se]=p[i].fi;
	rep(i,0,n) {
		printf("%d ",b[i]);
	}
	puts("");
}