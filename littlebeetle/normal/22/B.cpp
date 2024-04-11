#include<cstdio>
const int N=30;
int n,m,i,j,a,k,l,s[N][N],ans;
int max(int x,int y){
	return x>y?x:y;
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%1d",&a),
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+1-a;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			for(k=i+1;k<=n;k++)
				for(l=j+1;l<=m;l++)
					if(s[k][l]-s[k][j]-s[i][l]+s[i][j]==(k-i)*(l-j))
						ans=max(ans,2*(k-i+l-j));
	printf("%d",ans);
}