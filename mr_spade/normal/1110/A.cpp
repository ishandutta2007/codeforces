#include<cstdio>
const int N=1e5+5;
int b,k;
signed main()
{
	int res=0,x;
	register int i;
	scanf("%d%d",&b,&k);
	for(i=1;i<=k;i++)
		scanf("%d",&x),res=((long long)res*b+x)%2;
	puts(res&1?"odd":"even");
	return 0;
}