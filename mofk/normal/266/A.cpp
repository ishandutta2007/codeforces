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
	int i,n,cnt=0;
	char s[55];
	scanf("%d",&n);
	scanf("%s",&s);
	f(i,n-1) if(s[i]==s[i-1]) cnt++;
	printf("%d",cnt);
}