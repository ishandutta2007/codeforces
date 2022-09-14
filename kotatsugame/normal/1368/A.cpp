#include<cstdio>
using namespace std;
int T;
long long a,b,n;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%lld%lld%lld",&a,&b,&n);
		int cnt=0;
		while(a<=n&&b<=n)
		{
			cnt++;
			if(a<b)a+=b;
			else b+=a;
		}
		printf("%d\n",cnt);
	}
}