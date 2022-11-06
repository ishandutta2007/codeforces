#include<cstdio>
#include<map>
using std::map;
typedef unsigned long long ull;
const int base=31,mod=1e9+7;
const int N=2005;
int n,m;
char s[N];
ull H[N];
ull h1[N][N],h2[N][N];
ull powb[N],powm[N];
map<ull,int> M;
signed main()
{
	int n,m;
	register int i,j;
	scanf("%d%d",&n,&m);
	powb[0]=1;
	for(i=1;i<=n;i++)
		powb[i]=powb[i-1]*base;
	powm[0]=1;
	for(i=1;i<=n;i++)
		powm[i]=powm[i-1]*mod;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(j=1;j<=m;j++)
			h1[i][j]=h1[i][j-1]*base+s[j]-'a'+1;
		H[i]=H[i-1]*mod+(h1[i][m])%mod;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%s",s+1);
		for(j=1;j<=n;j++)
			h2[i][j]=h2[i][j-1]*base+s[j]-'a'+1;
	}
	ull now;
	for(i=1;i+m-1<=n;i++)
	{
		now=0;
		for(j=1;j<=m;j++)
			now=now*mod+(h2[j][i+m-1]-powb[m]*h2[j][i-1])%mod;
		M[now]=i;
	}
	for(i=1;i+m-1<=n;i++)
	{
		if(M.find(H[i+m-1]-powm[m]*H[i-1])!=M.end())
		{
			printf("%d %d\n",i,M[H[i+m-1]-powm[m]*H[i-1]]);
			return 0;
		}
	}
	return 0;
}