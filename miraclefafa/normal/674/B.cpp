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

const int N=1010;
int n,k,p[N],vis[N];
VI vec;
int main() {
	scanf("%d%d",&n,&k);
	rep(i,0,4) scanf("%d",p+i),vis[p[i]]=1;
	rep(i,1,n+1) if (!vis[i]) vec.pb(i);
	if (n==4||k<=n) {
		puts("-1");
		return 0;
	}
	printf("%d %d",p[0],p[2]);
	for (auto v:vec) printf(" %d",v);
	printf(" %d %d\n",p[3],p[1]);
	printf("%d %d",p[2],p[0]);
	for (auto v:vec) printf(" %d",v);
	printf(" %d %d\n",p[1],p[3]);
}