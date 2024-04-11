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
	long int cnt1=0,cnt0=0;
	int n,i,s[1005],flag=0;
	scanf("%d",&n);
	f(i,n) scanf("%d",&s[i]);
	f(i,n)
	{
		if(s[i]==1) {
			flag=1;
			cnt1++;
		}
		if(s[i]==0&&s[i-1]==1) cnt0++;
	}
	if(s[n]==0) cnt0--;
	if(flag) printf("%ld",cnt0+cnt1);
	else printf("0");
}