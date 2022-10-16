#include<cstdio>
#include<cstring>
#define F(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
using namespace std;
long long n;
int main()
{
	scanf("%lld",&n);
	if (n==1)return !printf("%lld",3ll);
	if (n==2)return !printf("%lld",5ll);
	return !printf("%lld",((n-3)/3+1)*4+3+n%3);
}