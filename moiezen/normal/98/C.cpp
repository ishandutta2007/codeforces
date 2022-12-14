#include <cstdio>
#include <cmath>
double l,a,b,t,ans,p,q,r,s,t1,t2;
int main(){
	scanf("%lf%lf%lf",&a,&b,&l);
	if(a>b) t=a,a=b,b=t;
	if(l<a+1e-8) ans=l;
	else if(l<b+1e-8) ans=a;
	else{
		p=0;q=1;
		for(int i=1;i<=100;i++){
			r=(2*p+q)/3;
			s=(p+2*q)/3;
			t1=a*r+b*sqrt(1-r*r)-l*r*sqrt(1-r*r);
			t2=a*s+b*sqrt(1-s*s)-l*s*sqrt(1-s*s);
			if(t1<t2) q=s;
			else p=r;
		}
		ans=t1;
	}
	if(ans<-1e-8) printf("My poor head =(");
	else printf("%.8f",ans);
}