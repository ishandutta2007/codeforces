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
	long int i,n,h[MAX]={0};
	scanf("%ld",&n);
	f(i,n) scanf("%ld",&h[i]);
	sort(h+1,h+n+1);
	printf("%ld",h[n]);
}