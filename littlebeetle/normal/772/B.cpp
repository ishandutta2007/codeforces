#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=2002;
int n,i,x[N],y[N];
double ans=1e15;
double Uzi(int a,int b,int c){
	double d1=sqrt(1ll*(x[a]-x[b])*(x[a]-x[b])+1ll*(y[a]-y[b])*(y[a]-y[b]));
	double d2=sqrt(1ll*(x[a]-x[c])*(x[a]-x[c])+1ll*(y[a]-y[c])*(y[a]-y[c]));
	double d3=sqrt(1ll*(x[c]-x[b])*(x[c]-x[b])+1ll*(y[c]-y[b])*(y[c]-y[b]));
	double p=(d1+d2+d3)/2;
	return 2*sqrt(p*(p-d1)*(p-d2)*(p-d3))/d3;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",x+i,y+i),x[n+i]=x[i],y[n+i]=y[i];
	for(i=2;i<=n+1;i++)
		ans=min(ans,Uzi(i,i-1,i+1));
	printf("%.10lf",ans/2);
	//while(1);
}