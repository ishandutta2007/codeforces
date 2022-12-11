#include<cstdio>
#include<cstring>
using namespace std;

const int md=998244353;
char s[3002],c[3002];
int f[4001][7001];
int main(){
	scanf("%s%s",s+1,c+1);
	int n=strlen(c+1),m=strlen(s+1);
	for(int i=1;i<=m+1;i++)
		f[i][i-1]=1;
	for(int l=0;l<m;l++)
		for(int i=1;i<=m+1;i++){
			int j=i+l-1;
			//printf("%d %d:%d\n",i,j,f[i][j]);
			if(j+1>n||s[l+1]==c[j+1])
				f[i][j+1]=(f[i][j+1]+f[i][j])%md;
			if(i-1>n||i-1>0&&s[l+1]==c[i-1])
				f[i-1][j]=(f[i-1][j]+f[i][j])%md;
		}
	int ans=0;
	for(int i=n;i<=m;i++)
		ans=(ans+f[1][i])%md;
	printf("%d\n",ans);
}