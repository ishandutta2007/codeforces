#include<cstdio>
const int N=2e5+5;
int n,a[N];
inline void swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
	return;
}
signed main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=(n>>1);i++)
		if(i&1)
			swap(a[i],a[n-i+1]);
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	putchar('\n');
	return 0;
}