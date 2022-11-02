#include<cstdio>
typedef long long ll;
const long long Inf=1000000000000000000ll;
const long long M=2005032220040413ll;
ll n,c,a,b,x,y,t,d;
void init(){
	scanf("%lld%lld%lld%lld",&n,&c,&a,&b);
}
void exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		d=a;x=1;y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=(a/b)*x;
}
ll Mult(ll x,ll y){
	ll s=0;
	while(x){
		if(x%2)
			s=(s+y)%M;
		x/=2;
		y=y*2%M;
	}
	return s;
}
ll Mix(ll x,ll y){
	int t=1;
	if(x<0)
		x=-x,t=-t;
	if(y<0)
		y=-y,t=-t;
	return t*Mult(x,y);
}
void Move(ll a,ll b,ll c,ll &x,ll &y){
	ll o=c/a;
	ll g=c%a;
	if(y<0){
		t=(-y*g+a-1)/a;
		x=(Mix(x,c)+Mix(Mix(y,o),b)-Mix(b,t)+M+M)%M;
		y=y*(c-o*a)+a*t;


	}
	else{
		t=(y*g)/a;
		//		printf("%lld %lld %lld %lld %lld\n",x,c,y,o*b,b*t);
				x=(Mix(x,c)+Mix(Mix(y,o),b)+Mix(b,t)+M+M)%M;
		y=y*(c-o*a)-a*t;


	}
	
	if(y<0){
		t=(-y+a-1)/a;
		y+=a*t;
		x-=b*t;
	}
	else{
		t=y/a;
		y-=a*t;
		x+=b*t;
	}
}
void work(){
	exgcd(a,b,x,y);
	if(c%d){
		printf("-1");
		return;
	}
	a/=d;b/=d;c/=d;
//	printf("%lld %lld\n",x,y);
	if(a>=b)
		Move(a,b,c,x,y);
	else
		Move(b,a,c,y,x);
//	printf("%lld %lld\n",x,y);
	if(x<0||y<0||x+y>n)
		printf("-1");
	else
		printf("%lld %lld %lld",x,y,n-x-y);
}
int main(){
	init();
	work();
	return 0;
}