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
#define INF 1000000007
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

#define maxn 1010
double f[maxn][maxn];
double prex[maxn],prey[maxn];
int a[maxn];
int n,m;
int main()
{
	read(n),read(m);
	for (int i=1;i<=n;i++)	read(a[i]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		if (a[i]>a[j])	f[i][j]=1;
	while (m--)
	{
		int x,y;
		read(x),read(y);
		if (x==y)	continue;
		for (int j=1;j<=n;j++)	prex[j]=f[j][x],prey[j]=f[j][y];
		for (int i=1;i<=n;i++)
		if (i!=x && i!=y)
			f[i][x]/=2,f[i][y]/=2,f[y][i]/=2,f[x][i]/=2;
		for (int i=1;i<=n;i++)
		if (i!=x && i!=y)
		{
			f[i][x]+=0.5*prey[i];
			f[i][y]+=0.5*prex[i];
		}
		for (int i=1;i<=n;i++)
		if (i!=x && i!=y)	f[x][i]=1.0-f[i][x],f[y][i]=1.0-f[i][y];
		f[x][y]=f[y][x]=0.5;
	}
	double mjy=0;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)	mjy+=f[i][j];
	printf("%.8lf\n",mjy);
	return 0;
}