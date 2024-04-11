#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,n,a[100];
long long k;
void solve(int n,long long k,int o=0)
{
	if(n==0)return;
	F(i,0,n)
	{
		long long tmp=1ll<<(n-i-2);
		if(i==n-1)tmp=1;
		if(k<tmp)
		{
			F(j,0,i+1)a[o+j]=o+i-j;
			solve(n-i-1,k,o+i+1);
			return;
		}
		else k-=tmp;
	}
}
int main()
{
	read(t);
	while(t--)
	{
		read(n);read(k);--k;
		if(n>61)
		{
			solve(61,k);
			F(i,0,n-61)printf("%d ",i+1);
			F(i,0,61)printf("%d ",a[i]+n-60);
		}
		else if(k<(1ll<<(n-1)))
		{
			solve(n,k);
			F(i,0,n)printf("%d ",a[i]+1);
		}
		else printf("-1");
		printf("\n");
	}
	return 0;
}