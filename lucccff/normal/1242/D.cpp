#include<iostream>
#include<cstdio>
using namespace std;
#define LL long long
int T;LL n,m;
inline LL Fin(LL w)
{
	if(!w)return m*(m+1)/2;LL p=w/m,x=Fin(p),t=w%m;
	return m*((m*m+1)*p+m*t)+m*(m+1)/2+max(0ll,min(m,(m*m+1)*p+t*m+m-x+1));
}
int main(){
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&m);LL p=(n-1)/(m*m+1),x=Fin(p),v1=(p%m+1+m*(p/m)),o=(n-1)%(m*m+1);
		printf("%lld\n",(n==x)?(v1*(m+1)):(n+p*m+((o-(n>x))/m)-v1+(x>n)));
	}return 0;
}