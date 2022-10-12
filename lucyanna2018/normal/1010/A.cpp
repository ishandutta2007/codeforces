#include<cstdio>
int n;double m,a[1010],b[1010];
bool chk1(double&x,double coef){
	double y = (x+m)/coef;
	if(x < y)return false;
	x-=y;
	return true;
}
bool chk(double x){
	for(int i=1; i<n; i++){
		if(!chk1(x,a[i]))return false;
		if(!chk1(x,b[i+1]))return false;
	}
	if(!chk1(x,a[n]))return false;
	if(!chk1(x,b[1]))return false;
	return true;
}
int main(){
	scanf("%d%lf",&n,&m);
	for(int i=1; i<=n; i++)scanf("%lf",&a[i]);
	for(int i=1; i<=n; i++)scanf("%lf",&b[i]);
	if(!chk(2e9))puts("-1");else{
		double lo = 0, hi = 2e9;
		for(int run = 0; run < 60; run ++){
			double mi = (lo + hi)/2;
			if(chk(mi))hi = mi;else
				lo = mi;
		}
		printf("%.12lf\n",lo);
	}
	return 0;
}