#include <cstdio>
long long a,b;
int ans;
int main()
{
	scanf("%I64d%I64d",&a,&b);
	ans=1;
	for(a++;a<=b;a++)
	{
		ans=(ans*(a%10))%10;
		if(ans==0) break;
	}
	printf("%d\n",ans);
    return 0;
}