#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

bool dp[210][210][210];
int r,g,b,n;
char s[210];
void dfs(int r,int g,int b) {
	if (dp[r][g][b]) return;
	dp[r][g][b]=1;
	if (r&&g) dfs(r-1,g-1,b+1);
	if (r&&b) dfs(r-1,g+1,b-1);
	if (g&&b) dfs(r+1,g-1,b-1);
	if (r>=2) dfs(r-1,g,b);
	if (g>=2) dfs(r,g-1,b);
	if (b>=2) dfs(r,g,b-1);
}
int main() {
	scanf("%d",&n);
	scanf("%s",s);
	rep(i,0,n) {
		if (s[i]=='R') r++;
		else if (s[i]=='G') g++;
		else if (s[i]=='B') b++;
	}
	dfs(r,g,b);
	if (dp[0][0][1]) putchar('B');
	if (dp[0][1][0]) putchar('G');
	if (dp[1][0][0]) putchar('R');
}