#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<queue>
#define mod 1000000007
#define f(i,n) for(i=1;i<=n;i++)
#define F(i,n) for(i=n;i>=1;i--)
#define FF(i,a,b) for(i=a;i>=b;i--)
#define ff(i,a,b) for(i=a;i<=b;i++)
#define B 1
#define W -1
typedef long long ll;
using namespace std;
const int MAX=(int)1e5+5;

int main(void)
{
	int i,j,cmd=0,rem=0,c[15][15];
	char s[15],p[15];
	scanf("%s%s",s,p);
	c[0][0]=1;
	f(i,10)
	{
		c[i][0]=1;c[i][i]=1;
	}
	ff(i,2,10) f(j,i-1) c[i][j]=c[i-1][j]+c[i-1][j-1];
	ff(i,0,strlen(s)-1) if(s[i]=='-') cmd--; else if(s[i]=='+') cmd++;
	ff(i,0,strlen(p)-1) if(p[i]=='+') cmd--; else if(p[i]=='-') cmd++; else rem++;
	if(cmd+rem<0||cmd>rem) printf("0.000000000");
	else printf("%.9f",(double)c[rem][(cmd+rem)/2]/pow(2,rem));
	return 0;
}