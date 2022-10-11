#include <iostream>
#include <string.h>
using namespace std;
char arr[100005];
long long n;
long long go(long long u,int idx)
{
	if (idx==strlen(arr))
	return u;
	long long tmp=(u&-u);
	if (arr[idx]=='L')
	u-=(tmp>>1);
	else if (arr[idx]=='R')
	u+=(tmp>>1);
	else if (u!=(n+1)/2)
	{
		if ((u^tmp)%(tmp<<2)==0)
		u+=tmp;
		else
		u-=tmp;
	}
	return go(u,idx+1);
}
int main()
{
	int q;
	scanf("%I64d%d",&n,&q);
	while (q--)
	{
		long long u;
		scanf("%I64d",&u);
		getchar();
		gets(arr);
		printf("%I64d\n",go(u,0));
	}
}