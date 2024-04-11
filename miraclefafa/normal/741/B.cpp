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
int n,m,v,w[N],b[N],f[N],u,vv;
int dp[N],pd[N];
int find(int x) { return f[x]==x?x:f[x]=find(f[x]); }
int main() {
	scanf("%d%d%d",&n,&m,&v);
	rep(i,1,n+1) scanf("%d",w+i);
	rep(i,1,n+1) scanf("%d",b+i);
	rep(i,1,n+1) f[i]=i;
	rep(i,0,m) {
		scanf("%d%d",&u,&vv);
		f[find(u)]=find(vv);
	}
	rep(i,1,n+1) if (find(i)==i) {
		VI itm; int sw=0,sb=0;
		rep(j,1,n+1) if (find(j)==i) itm.pb(j),sw+=w[j],sb+=b[j];
		rep(j,0,v+1) pd[j]=dp[j];
		for (auto p:itm) {
//			printf("%d %d\n",w[p],b[p]);
			rep(j,w[p],v+1) dp[j]=max(dp[j],pd[j-w[p]]+b[p]);
		}
		rep(j,sw,v+1) dp[j]=max(dp[j],pd[j-sw]+sb);
//		printf("%d %d\n",sw,sb);
//		puts("");
//		printf("%d\n",i);
	}
	printf("%d\n",dp[v]);
}