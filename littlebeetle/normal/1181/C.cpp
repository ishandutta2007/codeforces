#include<cstdio>
const int N=1002;
int n,m,i,j,k,l,u[N],f[N][N],ans;
char s[N][N];
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(k=1;k<=m;k++){
		for(i=1;i<=n;i++)
			u[i]=(s[i][k]==s[i-1][k])?u[i-1]+1:1;
		for(i=0;i<=n;i++)
			for(l=1;i+l*3<=n;l++){
				j=i+l*3;
				if(u[i+l]>=l&&u[i+l+l]==l&&u[j]==l){
					if(s[i+l][k]==s[i+l][k-1]&&s[i+l+l][k]==s[i+l+l][k-1]&&s[j][k]==s[j][k-1])
						f[i][j]++;
					else
						f[i][j]=1;
				}
				else
					f[i][j]=0;
				ans+=f[i][j];
			}
	}
	printf("%d",ans);
}