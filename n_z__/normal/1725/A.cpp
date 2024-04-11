#include<cstdio>
#include<cstring>
#define F(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
using namespace std;
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	if (m==1)return !printf("%d",n-1);
	printf("%lld",1ll*n*(m-1ll));
	return 0;
}