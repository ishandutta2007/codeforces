#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define sz size
#define fi first
#define se second
#define mp make_pair
#define pb push_back
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
#define maxn 20
double p[maxn][maxn];
long double f[maxn][1<<18];
int n;
int main()
{
	read(n);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			scanf("%lf",&p[i][j]);
	f[0][0]=1;
	for (int i=1,all=1<<n;i<all-1;i++)
		for (int j=0;j<n;j++)
		if ((i&(1<<j))==0)
		{
			long double mjy=0;
			for (int k=0;k<n;k++)
			if (i&(1<<k))
			{
				long double mxh=f[k][i^(1<<k)]*p[k][j]+f[j][i^(1<<k)]*p[j][k];
				if (mxh>mjy)	mjy=mxh;
			}
			f[j][i]=mjy;
		}
	long double mjy=0;
	int all=(1<<n)-1;
	for (int i=0;i<n;i++)
		mjy=max(mjy,f[i][all^(1<<i)]);
	printf("%.8lf\n",(double)mjy);
	return 0;
}