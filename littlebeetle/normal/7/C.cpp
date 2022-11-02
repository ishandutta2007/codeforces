#include<cstdio>
typedef long long ll;
ll a,b,c,d,x,y;
bool A,B,C;
void exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		d=a;
		x=1;y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=(a/b)*x;
}
int main(){
	scanf("%lld%lld%lld",&a,&b,&c);
	if(a<0)
		a=-a,A=1;
	if(b<0)
		b=-b,B=1;
	c=-c;
	exgcd(a,b,x,y);
	if(c%d){
		printf("-1");
		return 0;
	}
	c/=d;
	x*=c;y*=c;
	if(A)
		x=-x;
	if(B)
		y=-y;
	printf("%lld %lld",x,y);
	//while(1);
}