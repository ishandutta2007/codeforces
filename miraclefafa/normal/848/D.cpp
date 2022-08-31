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

const int N=55;
int n,m;
ll p[N][N],s[N][N],np[N][N],ff[N];
void upd(ll &a,ll b) {
	a=(a+b)%mod;
}
int main() {
	scanf("%d%d",&n,&m);
	p[0][1]=1;
	rep(i,0,n+1) {
		for (int p1=0;p1<=i-1;p1++) 
			for (int p2=1;p2<=p1+1;p2++)
				for (int p3=1;p3<=i-p1;p3++) {
					upd(s[i][min(p2,p3)],p[p1][p2]*p[i-1-p1][p3]);
				}
		if (i==0) continue;
		for (int p3=1;p3<=i+1;p3++) {
			memset(np,0,sizeof(np));
			ll r=1;
			for (int k=0;k*i<=n;k++) {
				ff[k]=r;
				r=r*(s[i][p3]+k)%mod*powmod(k+1,mod-2)%mod;
			}
			for (int p1=0;p1<=n;p1++) for (int p2=1;p2<=p1+1;p2++) {
				ll w=s[i][p3]; 
				for (int k=0;k*i+p1<=n;k++) {
					upd(np[k*i+p1][k*p3+p2],ff[k]*p[p1][p2]);
				}
			}
			memcpy(p,np,sizeof(np));
		}
	}
	printf("%lld\n",p[n][m]);
}