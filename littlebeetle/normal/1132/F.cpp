#include<cstdio>
const int N=502;
int n,i,j,k,l,f[N][N];
char s[N];
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;i++)
		f[i][i]=1;
	for(l=1;l<n;l++)
		for(i=1;i+l<=n;i++){
			j=i+l;
			f[i][j]=min(f[i+1][j],f[i][j-1])+1;
			for(k=i+1;k<=j;k++)
				if(s[i]==s[k])
					f[i][j]=min(f[i][j],f[i+1][k-1]+f[k][j]);
		}
	printf("%d",f[1][n]);
}