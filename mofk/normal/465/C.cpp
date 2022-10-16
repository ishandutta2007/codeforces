#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAX (int)1e5+5
#define f(i,n) for(i=1;i<=n;++i)
#define F(i,n) for(i=n;i>=1;--i)
#define FF(i,a,b) for(i=a;i>=b;--i)
#define ff(i,a,b) for(i=a;i<=b;++i)
typedef long long ll;
using namespace std;
int main(void)
{
	int i,n,p;
	char s[1005];
	scanf("%d%d",&n,&p);
	scanf("%s",&s);
	FF(i,n-1,0)
	{
		do s[i]++; while(s[i]==s[i-1]||s[i]==s[i-2]);
		if(s[i]<'a'+p) break;
	}
	if(s[0]>='a'+p) printf("NO");
	else
	{
		f(i,n-1) if(s[i]>='a'+p)
		{
			s[i]='a';
			while(s[i]==s[i-1]||s[i]==s[i-2]) s[i]++;
		}
		printf("%s",s);
	}
}