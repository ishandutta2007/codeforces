#include<cstdio>
const int N=200002;
const double eps=1e-7;
int n,i,a[N];
double l,r,lm,rm,u,v,b[N],s[N];
double fabs(double x){
	return x>0?x:-x;
}
double max(double x,double y){
	return x>y?x:y;
}
double f(double x){
	for(i=1;i<=n;i++)
		b[i]=a[i]-x,s[i]=s[i-1]+b[i];
	double Max=0,Min=0,ans=0;
	for(i=1;i<=n;i++){
		ans=max(max(Max-s[i],s[i]-Min),ans);
		if(s[i]>Max)Max=s[i];
		if(s[i]<Min)Min=s[i];
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	l=-10000;r=10000;
	while(1){
		lm=(l*2+r)/3;
		rm=(l+r*2)/3;
		u=f(lm);
		v=f(rm);
		if(fabs(u-v)<eps&&r-l<eps)
			break;
		if(u<v)
			r=rm;
		else
			l=lm;
	}
	printf("%.10lf",u<v?u:v);
}