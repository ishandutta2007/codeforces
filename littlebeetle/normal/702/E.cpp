#include<cstdio>
typedef long long ll;
const int N=100002,M=36;
int n,i,j,p,f[N][M],mi[N][M],x;
ll k,w[N][M],y;
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d%I64d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%d",f[i]),f[i][0]++;
	for(i=1;i<=n;i++)
		scanf("%I64d",w[i]),mi[i][0]=(int)w[i][0];
	for(j=0;j<M-1;j++)
		for(i=1;i<=n;i++){
			f[i][j+1]=f[f[i][j]][j];
			w[i][j+1]=w[i][j]+w[f[i][j]][j];
			mi[i][j+1]=min(mi[i][j],mi[f[i][j]][j]);
		}
	for(i=1;i<=n;i++){
		x=1<<30;
		y=0;
		j=i;
		for(p=0;p<M;p++){
			if(k>>p&1){
				x=min(x,mi[j][p]);
				y+=w[j][p];
				j=f[j][p];
			}
		}
		printf("%lld %d\n",y,x);
	}
}