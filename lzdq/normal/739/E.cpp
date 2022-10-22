#include<cstdio>
#include<algorithm>
const int MAXN=2005;
const double eps=1e-8;
int n,a,b;
double pa[MAXN],pb[MAXN];
double ca,cb;
int tot[MAXN][2];
double f[MAXN];
void Calc(){
	for(int i=1; i<=n; i++){
		f[i]=f[i-1];
		tot[i][0]=tot[i-1][0];
		tot[i][1]=tot[i-1][1];
		if(f[i]<f[i-1]+pa[i]-ca){
			f[i]=f[i-1]+pa[i]-ca;
			tot[i][0]=tot[i-1][0]+1;
			tot[i][1]=tot[i-1][1];
		}
		if(f[i]<f[i-1]+pb[i]-cb){
			f[i]=f[i-1]+pb[i]-cb;
			tot[i][0]=tot[i-1][0];
			tot[i][1]=tot[i-1][1]+1;
		}
		if(f[i]<f[i-1]+pa[i]+pb[i]-pa[i]*pb[i]-ca-cb){
			f[i]=f[i-1]+pa[i]+pb[i]-pa[i]*pb[i]-ca-cb;
			tot[i][0]=tot[i-1][0]+1;
			tot[i][1]=tot[i-1][1]+1;
		}
	}
	return ;
}
void Check(){
	double l=0,r=1;
	while(r-l>eps){
		cb=(l+r)/2;
		Calc();
		if(tot[n][1]==b){
			l=r=cb;
			break;
		}
		if(tot[n][1]>b) l=cb;
		else r=cb;
	}
	cb=l;
	Calc();
	return ;
}
int main(){
	//freopen("in","r",stdin);
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1; i<=n; i++)
		scanf("%lf",pa+i);
	for(int i=1; i<=n; i++)
		scanf("%lf",pb+i);
	double l=0,r=1;
	while(r-l>eps){
		ca=(l+r)/2;
		Check();
		if(tot[n][0]==a){
			l=r=ca;
			break;
		}
		if(tot[n][0]>a) l=ca;
		else r=ca;
	}
	ca=l;
	Check();
	//printf("ca %.2f cb %.2f\n",ca,cb); printf("tot0 %d tot1 %d\n",tot[n][0],tot[n][1]);
	printf("%f\n",f[n]+ca*a+cb*b);
	//printf("%f\n",f[n]+ca*tot[n][0]+cb*tot[n][1]);
	return 0;
}