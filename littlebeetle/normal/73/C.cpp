#include<cstdio>
const int N=702,K=102,M=26;
int n,k,m,f[N][K][M],v,g[M][M],i,j,l,p,ans=(-1<<30);
char s[N],t1[3],t2[3];
int max(int x,int y){
	return x>y?x:y;
}
int main(){
	scanf("%s%d",s+1,&k);
	while(s[n+1])n++;
	scanf("%d",&m);
	while(m--){
		scanf("%s%s%d",t1,t2,&v);
		g[t1[0]-97][t2[0]-97]=v;
	}
	for(i=0;i<=n;i++)
		for(j=0;j<=k;j++)
			for(l=0;l<26;l++)
				f[i][j][l]=-(1<<29);
	for(i=0;i<26;i++)
		if(i+97==s[1])
			f[1][0][i]=0;
		else
			f[1][1][i]=0;
	for(i=2;i<=n;i++)
		for(j=0;j<=k;j++)
			for(p=0;p<26;p++)
			for(l=0;l<26;l++){
				if(l+97==s[i])
					f[i][j][l]=max(f[i][j][l],f[i-1][j][p]+g[p][l]);
				else
					if(j>0)
						f[i][j][l]=max(f[i][j][l],f[i-1][j-1][p]+g[p][l]);
			}
	for(j=0;j<=k;j++)
	for(i=0;i<26;i++)
		ans=max(ans,f[n][j][i]);
	printf("%d",ans);
	//while(1);
}