#include <bits/stdc++.h>
using namespace std;
#define N 2005
#define MOD 1000000007
int T,n,m,ans;bool fl;char a[N][N];
void slv()
{
	scanf("%d %d",&n,&m);ans=1;fl=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",a[i]+1);
		for(int j=1;j<=m;++j)
			if(a[i][j]=='#') ans=ans*2%MOD;else fl=1;
	}ans-=!fl;printf("%d\n",(ans+MOD)%MOD);
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}