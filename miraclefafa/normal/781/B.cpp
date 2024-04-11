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
int n,val[N][2];
char a[30],b[30];
string g[N][2],s[N];
map<string,int> vis,p;
int dfs(int u) {
	rep(v,0,2) if (val[u][v]&&!vis[g[u][v]]) {
		string c=g[u][v];
		vis[c]=1;
		if (p[c]==0||dfs(p[c])) { p[c]=u; s[u]=c; return 1;}
	}
	return 0;
}
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) {
		scanf("%s%s",a,b);
		g[i][0]=string{a[0],a[1],a[2]};
		g[i][1]=string{a[0],a[1],b[0]};
	}
	rep(i,1,n+1) {
		val[i][0]=val[i][1]=1;
		rep(j,1,n+1) if (i!=j&&g[i][0]==g[j][0]) {
			val[i][0]=0; break;
		}
		vis.clear();
		if (!dfs(i)) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	rep(i,1,n+1) printf("%s\n",s[i].c_str());
}