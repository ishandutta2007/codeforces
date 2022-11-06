#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mpr make_pair
#define fi first
#define se second
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define N 59
using namespace std;

int n,m; ll a[N],s[N]; bool dp[N][N];
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
bool check(ll x){
	int i,j,k;
	memset(dp,0,sizeof(dp)); dp[0][0]=1;
	for (i=1; i<=n; i++)
		for (j=1; j<=m; j++)
			for (k=0; k<i; k++) if (dp[k][j-1] && ((s[i]-s[k]&x)==x)){
				dp[i][j]=1; break;
			}
	return dp[n][m];	
}
int main(){
	n=read(); m=read();
	int i; ll ans=0;
	for (i=1; i<=n; i++){
		scanf("%lld",&a[i]); s[i]=s[i-1]+a[i];	
	}
	for (i=60; i>=0; i--)
		if (check(ans|1ll<<i)) ans|=1ll<<i;
	printf("%lld\n",ans);
	return 0;
}