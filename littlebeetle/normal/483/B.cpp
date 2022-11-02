#include<cstdio>
typedef long long ll;
ll x,y,cnt1,cnt2,l,r,mid,a,b,c,s1,s2;
bool check(ll p){
	a=p/x;
	b=p/y;
	c=p/x/y;
	a-=c;b-=c;
	s1=cnt1-b;
	if(s1<0)s1=0;
	s2=cnt2-a;
	if(s2<0)s2=0;
	p-=a+b+c;
	if(s1+s2<=p)
		return 1;
	else
		return 0;
}
int main(){
	scanf("%lld%lld%lld%lld",&cnt1,&cnt2,&x,&y);
	l=0;r=1ll<<60;
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