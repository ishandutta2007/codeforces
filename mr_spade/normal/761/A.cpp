#include<cstdio>
inline int abs(int x)
{
	return x>0?x:(-x);
}
signed main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(!(a||b))
	{
		puts("NO");
		return 0;
	}
	puts(abs(a-b)<=1?"YES":"NO");
	return 0;
}