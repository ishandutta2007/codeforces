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
	int n,i,j,cnt,flag=0;
	char s[105][105];
	scanf("%d",&n);
	ff(i,0,n-1) scanf("%s",&s[i]);
	ff(i,0,n-1) ff(j,0,n-1)
	{
		cnt=0;
		if(s[i][j+1]=='o') cnt++;
		if(s[i][j-1]=='o') cnt++;
		if(s[i+1][j]=='o') cnt++;
		if(s[i-1][j]=='o') cnt++;
		if(cnt%2!=0) flag=1;
	}
	if(flag) printf("NO");else printf("YES");
}