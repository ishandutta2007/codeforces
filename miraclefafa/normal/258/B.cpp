#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
const int p=1e9+7;
int m,l,a[20],b[20],ans,sum,dp[20][30],dp2[20][30],dp3[200],dp4[200];
long long s;
void dfs(int step,int tot,long long val) {
	if (step==7) {ans=(ans+dp4[tot+1]*val)%p;return;}
	for (int k=0;dp3[k];k++) {
		b[k]++;
		dfs(step+1,tot+k,val*(dp3[k]-b[k]+1)%p);
		b[k]--;
	}
}
int main() {
//	freopen("data.in","r",stdin);
	scanf("%d",&m);m++;
	s=1;l=1;
	for (;s<=m;s*=10,l++) a[l]=m%(s*10)/s;
	dp[0][0]=1;
	for (int i=1;i<l;i++) {
		for (int j=0;j<a[l-i];j++) {
			memset(dp2,0,sizeof(dp2));
			for (int k=0;k<=20;k++) dp2[i][k+(j==4||j==7)]=dp[i-1][k];
			for (int k=i+1;k<l;k++) for (int k2=0;k2<=20;k2++) for (int l=0;l<=9;l++)
				dp2[k][k2+(l==4||l==7)]+=dp2[k-1][k2];
			for (int k2=0;k2<=20;k2++) dp3[k2]+=dp2[l-1][k2];
		}
		for (int k=0;k<=20;k++) dp[i][k+(a[l-i]==4||a[l-i]==7)]+=dp[i-1][k];
	}
	dp3[0]--;
	for (int k=100;k>=0;k--) dp4[k]=(dp3[k]+dp4[k+1])%p;
	dfs(1,0,1);
	printf("%d\n",ans);
}