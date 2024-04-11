#include<cstdio>
#include<cmath>
#define max(a,b) (a>b?a:b)
const int N=1e5+5;
int n,x,num[N],a;
inline void swap(int &a,int &b)
{
	int t;
	t=a;
	a=b;
	b=t;
	return;
}
inline int f(int x)
{
	if(x%4==1)
		return 1;
	if(x%4==2)
		return x+1;
	if(x%4==3)
		return 0;
	if(x%4==0)
		return x;
}
signed main()
{
	int i,j;
	scanf("%d%d",&n,&x);
	if(n==1&&x==0)
	{
		puts("YES");
		puts("0");
		return 0;
	}
	if(n==2&&x==0)
	{
		puts("NO");
		return 0;
	}
	for(i=1;i<=n;i++)
		num[i]=i;
	a=f(n);
	for(i=0;i<=(int)log2(max(n,x));i++)
		if(((x>>i)&1)^((a>>i)&1))
			num[n]+=(((num[n]>>i)&1)?(-(1<<i)):(1<<i));
	if(num[n]<n-1)
	{
		num[n-1]+=(1<<((int)log2(max(n,x))+1));
		num[n]+=(1<<((int)log2(max(n,x))+1));
		if(num[n-1]>num[n])
			swap(num[n-1],num[n]);
	}
	else if(num[n]==n-1)
	{
		num[n-2]+=(1<<((int)log2(max(n,x))+1));
		num[n]+=(1<<((int)log2(max(n,x))+1));
		swap(num[n-1],num[n-2]);
		if(num[n-1]>num[n])
			swap(num[n-1],num[n]);
	}
	if(num[n]>1000000)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for(i=1;i<=n;i++)
		printf("%d ",num[i]);
	putchar('\n');
	return 0;
}
/*1 n+1 0 n*/