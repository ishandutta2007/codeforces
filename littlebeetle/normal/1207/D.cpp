#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=300003,M=998244353;
struct p{
	ll a,b;
}x[N];
ll n,i,j,sum,s,k,u,v;
ll fac(ll x){
	ll s=1;
	while(x){
		s=s*x%M;
		x--;
	}
	//printf("   %lld %lld\n",x,s);
	return s;
}
void init(){
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld%lld",&x[i].a,&x[i].b);
}
bool cmp1(p u,p v){
	return u.a<v.a;
}
bool cmp2(p u,p v){
	return u.b<v.b;
}
ll work3(ll L,ll R){
	ll ss=1,k=1;
	for(u=L+1;u<=R;u++)
		if(x[u].a==x[u-1].a)
			k++;
		else
			ss=ss*fac(k)%M,k=1;
	ss=ss*fac(k)%M;
	return ss;
}
ll work2(){
	s=1;
	for(i=1;i<=n;i=j+1){
		j=i;
		while(x[i].b==x[j+1].b)
			j++;
		sort(x+i,x+j+1,cmp1);
		if(x[i-1].a>x[i].a)
			return 0;
		s=s*work3(i,j)%M;
	}
	return s;
}
void work(){
	s=1;
	sort(x+1,x+n+1,cmp1);
	for(i=1;i<=n+1;i++)
		if(x[i].a!=x[i-1].a)
			s=s*fac(k+1)%M,k=0;
		else
			k++;
	sort(x+1,x+n+1,cmp2);
	//printf("%lld\n",s);
	sum=(sum+s)%M;
	s=1;
	for(i=1;i<=n+1;i++)
		if(x[i].b!=x[i-1].b)
			s=s*fac(k+1)%M,k=0;
		else
			k++;
	sum=(sum+s)%M;
	//printf("%lld\n",s);
	sum=(sum-work2()+M)%M;
	//printf("%lld\n",s);
	printf("%lld",(fac(n)-sum+M)%M);
}
int main(){
	init();
	work();
}