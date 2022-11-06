#include<cstdio>
#include<algorithm>
using std::min;
int a,b,c;
signed main()
{
	scanf("%d%d%d",&a,&b,&c);
	a+=2;b+=1;
	printf("%d\n",min(a,min(b,c))*3-3);
	return 0;
}