#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAX (int)1e5+5
#define f(i,n) for(i=1;i<=n;++i)
#define F(i,n) for(i=n;i>=1;--i)
#define ff(i,a,b) for(i=a;i<=b;++i)
typedef long long ll;
using namespace std;
int main(void)
{
	ll i,n,a[MAX],b[MAX]={0},ans,fa,fb,fc,maxx=0;
	scanf("%I64d",&n);
	f(i,n)
	{
		scanf("%I64d",&a[i]);
		if(a[i]>maxx) maxx=a[i];
		b[a[i]]+=a[i];
	}
	fa=0;fb=b[1];
	ff(i,2,maxx)
	{
		fc=max(fb,fa+b[i]);
		fa=fb;fb=fc;
	}
	printf("%I64d",fc);
}