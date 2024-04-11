#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
LL a1,b1,a2,b2,l,r;
void exgcd(LL a,LL b,LL &d,LL &x,LL &y){
	if(!b){
		x=1;
		y=0;
		d=a;
		return;
	}
	exgcd(b,a%b,d,y,x);
	y-=a/b*x;
}
LL gcd(LL a,LL b){
	LL t;
	while(b){
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int main()
{
	scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&a1,&b1,&a2,&b2,&l,&r);
	if(a1<a2)
		swap(a1,a2),swap(b1,b2);
	LL xa,xb;
	xa=b1+max((l-b1+a1-1)/a1,0ll)*a1,xb=b2+max((l-b2+a2-1)/a2,0ll)*a2;
	if(xa>r||xb>r){
		puts("0");
		return 0;
	}
	if(xa==xb){
		printf("%I64d\n",(r-xa)/(a1*a2/gcd(a1,a2))+1);
	}
	else{
		LL d,x,y,delta=((xb-xa)%a2+a2)%a2;
		exgcd(a1,a2,d,x,y);
		if(delta%d){
			puts("0");
			return 0;
		}
		x*=delta/d,y*=delta/d;
		if(y>0){
			x+=a2/(gcd(a1,a2))*((y-1)/(a1/gcd(a1,a2))+1);
			if(x<0)
				x=(x%(a2/gcd(a1,a2)))+a2/gcd(a1,a2);
		}
		else{
			y=-y;
			x-=a2/(gcd(a1,a2))*(y/(a1/gcd(a1,a2)));
		}
		xa+=x*a1;
		if(xa<xb)
			xa+=((xb-xa-1)/(a1*a2/gcd(a1,a2))+1)*(a1*a2/gcd(a1,a2));
		if(xa>r)
			puts("0");
		else
			printf("%I64d\n",(r-xa)/(a1*a2/gcd(a1,a2))+1);
	}
}