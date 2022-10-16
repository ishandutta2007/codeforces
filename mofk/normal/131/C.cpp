#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAX (int)1e5+5
#define f(i,n) for(i=1;i<=n;i++)
#define F(i,n) for(i=n;i>=1;i--)
#define ff(i,a,b) for(i=a;i<=b;i++)
typedef long long ll;
using namespace std;
int main(void)
{
	int n,i,j,m,t;
	ll ans=0,c[31][31]={0};
	scanf("%d%d%d",&n,&m,&t);
	f(i,30) {c[0][i]=1;c[i][i]=1;}
	ff(i,2,30) f(j,i-1) c[j][i]=c[j][i-1]+c[j-1][i-1];
	ff(i,max(4,t-m),min(n,t-1)) ans+=c[i][n]*c[t-i][m];
	printf("%I64d",ans);
}