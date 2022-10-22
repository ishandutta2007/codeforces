#include<cstdio>
int k,n,w;
inline double max(double a,int b){return a>b?a:b;}
main(){
	scanf("%d%d%d",&k,&n,&w);
	printf("%.0lf",max(double(w+1)*w*0.5*k-n,0));
}