#include<cstdio>
#include<cmath>
using namespace std;
const int N=100200;
const double Pi=acos(-1);
long double Max(long double x,long double y){
	return x>y?x:y;
}
long double Min(long double x,long double y){
	return x<y?x:y;
}
long long  n,i,u,v,x[N],y[N];
long double mind=1e20,maxd=-1e20,d;
	double ans;
long double Dis(int a,int b){
	long double dis1=sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
	long double dis2=sqrt((x[0]-x[b])*(x[0]-x[b])+(y[0]-y[b])*(y[0]-y[b]));
	long double dis3=sqrt((x[a]-x[0])*(x[a]-x[0])+(y[a]-y[0])*(y[a]-y[0]));
	long double p=(dis1+dis2+dis3)/2;
	return sqrt(p*(p-dis1)*(p-dis2)*(p-dis3))*2/dis1;
}	
int main(){
	scanf("%lld%lld%lld",&n,x,y);
	for(i=1;i<=n;i++){
		scanf("%lld%lld",x+i,y+i);
		d=sqrt((x[i]-x[0])*(x[i]-x[0])+(y[i]-y[0])*(y[i]-y[0]));
		mind=Min(mind,d);
		maxd=Max(maxd,d);
	}
	x[n+1]=x[1];
	y[n+1]=y[1];
	for(i=1;i<=n;i++)
		if((x[i+1]-x[i])*(x[0]-x[i])+(y[i+1]-y[i])*(y[0]-y[i])>0&&
			(x[i]-x[i+1])*(x[0]-x[i+1])+(y[i]-y[i+1])*(y[0]-y[i+1])>0)
				mind=Min(mind,Dis(i,i+1));
	//printf("%Lf %Lf\n",maxd,mind);
	ans=Pi*(maxd*maxd-mind*mind);
	printf("%.10lf",ans);
	//while(1);
	return 0;
}