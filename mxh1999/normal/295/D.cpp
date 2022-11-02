//This is meng meng da mjy>_<
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;

void read(int &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}

const ll mo=1000000007;
#define maxn 2010
ll f[maxn][maxn];
ll g[maxn][maxn];
ll pre[maxn][maxn],pre2[maxn][maxn];
ll mjy;
int n,m;

int main()
{
	read(n),read(m);
	f[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=m;j++)
		{
			if (i==1)	f[i][j]=1;else
			//f[i][j]= sigma f[i-1][k]*(j-k+1)
			f[i][j]=((pre[i-1][j]*(j+1)-pre2[i-1][j])%mo+mo)%mo;
		}
		pre[i][0]=f[i][0];
		for (int j=1;j<=m;j++)
		{
			pre[i][j]=(pre[i][j-1]+f[i][j])%mo;
			pre2[i][j]=(pre2[i][j-1]+f[i][j]*j)%mo;
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=0;j<=m;j++)
			g[i][j]=(g[i-1][j]+f[i][j])%mo;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=m-2;j++)
			mjy=(mjy+(g[i][j]*(g[n-i+1][j]-g[n-i][j]+mo)%mo)%mo*(m-1-j))%mo;
	cout<<mjy<<endl;
	return 0;
}