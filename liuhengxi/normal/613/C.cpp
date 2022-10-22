#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=27,M=1e5+5;
int n,a[N],cnt,g,sp;
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int main()
{
	scanf("%d",&n);
	F(i,0,n)scanf("%d",&a[i]);
	F(i,0,n)if(a[i]&1)++cnt;
	if(cnt>=2)
	{
		puts("0");
		F(i,0,n)F(j,0,a[i])putchar('a'+i);
		puts("");
		return 0;
	}
	F(i,0,n)g=gcd(g,a[i]);
	F(i,0,n)a[i]/=g;
	if(cnt==1)
	{
		printf("%d\n",g);
		F(i,0,n)if(a[i]&1)sp=i;
		F(i,0,g)
		{
			F(j,0,n)F(k,0,a[j]/2)putchar('a'+j);
			putchar('a'+sp);
			for(int j=n;~j;--j)F(k,0,a[j]/2)putchar('a'+j);
		}
		puts("");
		return 0;
	}
	printf("%d\n",g);
	F(i,0,g/2)
	{
		F(j,0,n)F(k,0,a[j])putchar('a'+j);
		for(int j=n;~j;--j)F(k,0,a[j])putchar('a'+j);
	}
	puts("");
	return 0;
}