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

const int N=101000;
ll dp[N][3][3];
int n;
char s[N],t[N];
void upd(int x,int a,int b,ll c) {
	if (a>=2||b>=2) return;
	dp[x][a][b]+=c;
}
int main() {
	scanf("%d",&n);
	scanf("%s%s",s,t);
	dp[0][0][0]=1;
	rep(i,0,n+1) rep(j,'a','z'+1) rep(p1,0,2) rep(p2,0,2) if (dp[i][p1][p2]) {
		upd(i+1,p1+(j!=s[i-p1]),p2+(j!=t[i-p2]),dp[i][p1][p2]);
	}
	printf("%I64d\n",dp[n+1][1][1]);
}