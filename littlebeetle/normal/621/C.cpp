#include<cstdio>
const int N=100002;
int n,i,x,l,r;
double p[N],ans;
int main(){
	scanf("%d%d",&n,&x);
	for(i=1;i<=n;i++){
		scanf("%d%d",&l,&r);
		p[i]=1.0*(r/x-(l-1)/x)/(r-l+1);
	}
	p[n+1]=p[1];
	for(i=1;i<=n;i++)
		ans+=2000*(p[i]+p[i+1]-p[i]*p[i+1]);
	printf("%.10lf",ans);
	//while(1);
}