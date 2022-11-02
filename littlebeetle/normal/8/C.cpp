#include<cstdio>
#include<cstring>
using namespace std;
const int N=24,M=1<<24;
int n,a,b,i,j,k,x[N],y[N],d[N],D[N][N],f[M];
int min(int x,int y){
	return x<y?x:y;
}
void Out(int i){
	if(i==0){
		printf("0 ");
		return;
	}
	printf("0 ");
	for(int j=0;j<n;j++)
		for(int k=0;k<n;k++)
			if((i>>j&1)&&(i>>k&1)){
				if(f[i]==f[i^(1<<j)]+(d[j]<<1)){
					printf("%d ",j+1);
					Out(i^(1<<j));
					return;
				}
				if(j!=k&&f[i]==f[i^(1<<j)^(1<<k)]+D[j][k]){
					printf("%d %d ",j+1,k+1);
					Out(i^(1<<j)^(1<<k));
					return;
				}
			}
}
int main(){
	scanf("%d%d%d",&a,&b,&n);
	for(i=0;i<n;i++){
		scanf("%d%d",x+i,y+i);
		d[i]=(x[i]-a)*(x[i]-a)+(y[i]-b)*(y[i]-b);
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			D[i][j]=d[i]+d[j]+(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
	memset(f,13,sizeof(f));
	f[0]=0;
	for(i=0;i<(1<<n);i++){
		k=-1;
		for(j=0;j<n;j++)
			if(!(i>>j&1)){
				if(!(~k))k=j;
				f[i|1<<j]=min(f[i|1<<j],f[i]+(d[j]<<1));
				f[i|1<<j|1<<k]=min(f[i|1<<j|1<<k],f[i]+D[k][j]);
			}
	}
	printf("%d\n",f[(1<<n)-1]);
	Out((1<<n)-1);
}