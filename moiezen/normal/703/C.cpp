#include <cstdio>
#define rpt(i,l,r) for(int i=l;i<=r;i++)
#define N 10005
int n,w,v,u,x[N],y[N],x1,y1,x2,y2;
double ans1,ans2;
double maxv(double a,double b){
	return a>b?a:b;
}
double minv(double a,double b){
	return a<b?a:b;
}
int main(){
	scanf("%d%d%d%d",&n,&w,&v,&u);
	ans1=w*1.0/u;ans2=w*1.0/u;
	rpt(i,1,n) scanf("%d%d",&x[i],&y[i]);
	x[n+1]=x[1];y[n+1]=y[1];
	rpt(i,1,n){
		x1=x[i];y1=y[i];x2=x[i+1];y2=y[i+1];
		if(x1<x2&&y1<=y2) ans2=maxv(ans2,maxv(x1*1.0/v+(w-y1)*1.0/u,x2*1.0/v+(w-y2)*1.0/u));
		if(y1>=y2) if(x1*1.0/v<y1*1.0/u-1e-8||x2*1.0/v<y2*1.0/u-1e-8) ans1=1e10;
	}
	printf("%.10f",minv(ans1,ans2));
}
/*
5 5 1 2
1 2
3 1
4 3
3 4
1 4

5.0000000000
*/