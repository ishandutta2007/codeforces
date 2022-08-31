#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <bitset>
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

bitset<2001> nst,st,zero;
int n,k,x,vis[1010],a[1010],m;
int main() {
	scanf("%d%d",&n,&k);
	rep(i,0,k) {
		scanf("%d",&x);
		vis[x]=1;
	}
	m=0;
	rep(i,0,1001) if (vis[i]) a[m++]=i-n;
	st[1000]=1;
	rep(i,1,1001) {
		nst=zero;
		rep(j,0,m) if (a[j]>0) nst|=(st<<a[j]); else nst|=(st>>(-a[j]));
		st=nst;
		if (st[1000]==1) {
			printf("%d\n",i);
			return 0;
		}
	}
	puts("-1");
}