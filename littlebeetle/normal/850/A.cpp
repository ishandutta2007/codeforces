#include<cstdio>
#include<cmath>
using namespace std;
const int N=1002;
int n,i,j,k,a,b,x[N][5],tmp,f[N],cnt,xo;
double d[N][N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(k=0;k<5;k++)
			scanf("%d",x[i]+k);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i!=j){
				for(k=0;k<5;k++)
					d[i][j]+=(x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
				d[i][j]=sqrt(d[i][j]);
			}
	for(i=1;i<=n;i++){
		tmp=1;
		for(j=1;j<=n&&tmp;j++)
			if(i!=j)
				for(k=1;k<=n;k++)
					if(k!=i&&k!=j){
					xo=0;
					for(a=0;a<5;a++)
						xo+=(x[j][a]-x[i][a])*(x[k][a]-x[i][a]);
					if(xo>0){
						tmp=0;
						break;
					}
				}
		if(tmp)
			f[++cnt]=i;
	}
	printf("%d\n",cnt);
	for(i=1;i<=cnt;i++)
		printf("%d\n",f[i]);
	//while(1);
}