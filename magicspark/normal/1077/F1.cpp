#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int > vi;
typedef pair<int ,int > pii;
typedef vector<pii> vii;
const int inf=0x3f3f3f3f, maxn=100007, mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3fLL;
int a[2007],n,k,x;
ll dp[2007][2007];//dp[i][j]ij 

int main(){
    for(int i=0;i<100;i++)cout<<"";
	scanf("%d%d%d",&n,&k,&x);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=x;j++)dp[i][j]=-linf;
	}
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=x;j++){
			if(j==1&&i<=k)dp[i][j]=a[i];
			else if(j>1)for(int kk=max(1,i-k);kk<i;kk++){
				dp[i][j]=max(dp[kk][j-1]+a[i],dp[i][j]);
			}
		}
	}
	ll ans=-1;

	for(int i=n-k+1;i<=n;i++)ans=max(ans,dp[i][x]);
	printf("%I64d",ans);
	return 0;
}