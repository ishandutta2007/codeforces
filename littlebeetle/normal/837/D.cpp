#include<cstdio>
const int N=202,M=6002;
int f[N][M];
int n,k,i,j,x,y,ans;
long long a;
int max(int x,int y){
	return x>y?x:y;
}
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d%d",&n,&k);
	for(i=0;i<N;i++)
	for(j=0;j<M;j++)
	f[i][j]=-100000;
	f[0][0]=0;
	while(n--){
		scanf("%lld",&a);
		x=y=0;
		while(a%5==0)x++,a/=5;
		while(a%2==0)y++,a/=2;
		for(i=k;i;i--)
			for(j=M-1;j>=x;j--)
				f[i][j]=max(f[i][j],f[i-1][j-x]+y);
	}
	for(j=0;j<=k;j++)
	for(i=1;i<M;i++)
		ans=max(ans,min(i,f[j][i]));
	printf("%d",ans);
}