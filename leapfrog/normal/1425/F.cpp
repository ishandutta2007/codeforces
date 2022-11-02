//xtwakioi! xtwddYnoi()!
#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
#define mk make_pair
using namespace std; const int N=600010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,a[N],b[N];
signed main()
{
	scanf("%lld",&n);
	for(ri int i=2;i<=n;i++)
	{
		printf("? 1 %lld\n",i);
		fflush(stdout);
		scanf("%lld",&b[i]);
	}
	for(ri int i=3;i<=n;i++) a[i]=b[i]-b[i-1];
	printf("? 2 %lld\n",n), fflush(stdout);
	scanf("%lld",&a[2]);
	for(ri int i=3;i<=n;i++) a[2]-=a[i];
	printf("! %lld ",b[2]-a[2]);
	for(ri int i=2;i<=n;i++) printf("%lld ",a[i]);
	puts(""), fflush(stdout);
    return 0;
}