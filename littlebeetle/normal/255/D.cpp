#include<cstdio>
typedef long long ll;
ll n,x,y,c,l,r,mid;
ll s1,s2,s3,s4,s5,s6,s7,s8,s9;
void init(){
	scanf("%lld%lld%lld%lld",&n,&x,&y,&c);
}
ll Get(ll x){
	return x*x;
}
ll G(ll x){
	return x*(x+1)/2;
}
bool check(ll p){
	ll s1=2*p*(p+1)+1;
	s2=s3=s4=s5=s6=s7=s8=s9=0;
	if(x+p>n)s2=Get(x+p-n);
	if(y+p>n)s3=Get(y+p-n);
	if(x-p<1)s4=Get(p-x+1);
	if(y-p<1)s5=Get(p-y+1);
	if(x+y+p>n*2+1)s6=G(x+y+p-n*2-1);
	if(x+p-n-y+1>1)s7=G(x+p-n-y+1-1);
	if(y+p-n-x+1>1)s8=G(y+p-n-x+1-1);
	if(p-x+1-y+1>1)s9=G(p-x+1-y+1-1);
	return s1-s2-s3-s4-s5+s6+s7+s8+s9>=c;
}
void work(){
	l=0;r=n*2;
	while(l<r){
		mid=l+r>>1;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	printf("%lld",r);
	//while(1);
}
int main(){
	init();
	work();
	//while(1);
	return 0;
}