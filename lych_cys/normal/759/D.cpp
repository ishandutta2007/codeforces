#include<bits/stdc++.h>
#define N 5005
#define ll long long
#define mod 1000000007
using namespace std;
int n,f[N][26],dp[N][N],a[N]; char s[N];
int main(){
	scanf("%d",&n);
	int i,j,k;
	scanf("%s",s+1);
	for (i=1; i<=n; i++) a[i]=s[i]-'a';
	for (i=n; i>=0; i--){
		for (j=0; j<26; j++) f[i][j]=f[i+1][j];
		if (i<n)f[i][a[i+1]]=i+1;
	}int sum,tmp[26];
	//for (i=0; i<26; i++) if (f[0][i]) dp[1][f[0][i]]=1;//,printf("%d\n",f[0][i]);
	for (i=1;i<=n;i++)dp[1][i]=1;
	for (i=2; i<=n; i++){sum=0;memset(tmp,0,sizeof(tmp));
		for (j=1; j<=n; j++) {
			//cout<<i<<' '<<j<<endl;
			sum-=tmp[a[j]];tmp[a[j]]=dp[i-1][j];sum+=tmp[a[j]];sum=(sum%mod+mod)%mod;
			//dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
			//cout<<sum<<endl;
			dp[i][j]=sum;//cout<<i<<' '<<j<<' '<<dp[i][j]<<' '<<tmp[1]<<endl;
			//for (k=0; k<26;k++) if (a[j]!=k && f[j][k]) dp[i+1][f[j][k]]=(dp[i+1][f[j][k]]+dp[i][j])%mod;
		}}memset(tmp,0,sizeof(tmp));
	for (i=n;i;i--)if(!tmp[a[i]]){tmp[a[i]]=1;dp[n][0]=(dp[n][0]+dp[n][i])%mod;}
		cout<<dp[n][0]<<endl;
	return 0;
}