#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int mod=1e9+7;
int n,m;
char s[205];
int f[205][105][205],kmp[205],nx[205][2],ans;
int Fstpw(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=1ll*res*a%mod;
		b>>=1;
		a=1ll*a*a%mod;
	}
	return res;
}
int main(){
	//freopen("in","r",stdin);
	scanf("%d",&n);
	scanf("%s",s+1);
	m=strlen(s+1);
	for(int i=2,j=0; i<=m; i++){
		while(j&&s[j+1]!=s[i]) j=kmp[j];
		if(s[j+1]==s[i]) j++;
		kmp[i]=j;
	}
	for(int i=0; i<m; i++){
		int c=(s[i+1]==')');
		nx[i][c]=i+1;
		nx[i][!c]=nx[kmp[i]][!c];
	}
	ans=1;
	for(int i=1; i<=n; i++)
		ans=1ll*ans*i%mod;
	ans=Fstpw(ans,mod-2);
	for(int i=n+2; i<=n*2; i++)
		ans=1ll*ans*i%mod;
	f[0][0][0]=1;
	for(int i=0; i<n*2; i++)
		for(int j=0; j<=n; j++)
			for(int k=0; k<m; k++){
				f[i+1][j+1][nx[k][0]]=(f[i+1][j+1][nx[k][0]]+f[i][j][k])%mod;
				if(j) f[i+1][j-1][nx[k][1]]=(f[i+1][j-1][nx[k][1]]+f[i][j][k])%mod;
			}
	for(int i=0; i<m; i++)
		ans=(ans-f[n*2][0][i]+mod)%mod;
	printf("%d\n",ans);
	return 0;
}