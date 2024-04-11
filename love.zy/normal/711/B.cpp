#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <deque>
#include <bitset>
#include <algorithm>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define scan2(x, y) scanf("%d%d", &x, &y)
#define scan3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lc o << 1
#define rc o << 1 | 1
#define lowbit(x) (x&(-x))
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
  
const LL mi=1;
const LL ma=1e18;

LL a[505][505];
int i,j,k,l,m,n;
LL tot[2],tt;
bool f;

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)scanf("%lld",&a[i][j]);
	f=true;
	for(i=1;i<=n;i++)
	{
		tt=0;k=0;
		for(j=1;j<=n;j++)
		{
			tt+=a[i][j];
			if(a[i][j]==0)k=1;
		}
		if(tot[k]==0)tot[k]=tt;
		else if(tt!=tot[k])
		{
			f=false;
			break;
		}
		if(!f)break;
		tt=0;k=0;
		for(j=1;j<=n;j++)
		{
			tt+=a[j][i];
			if(a[j][i]==0)k=1;
		}
		if(tot[k]==0)tot[k]=tt;
		else if(tt!=tot[k])
		{
			f=false;
			break;
		}
		if(!f)break;
	}
	tt=0;k=0;
	for(i=1;i<=n;i++)
	{
		tt+=a[i][i];
		if(a[i][i]==0)k=1;
	}
	if(tot[k]==0)tot[k]=tt;
	else if(tt!=tot[k])f=false;
	tt=0;k=0;
	for(i=1;i<=n;i++)
	{
		tt+=a[i][n-i+1];
		if(a[i][n-i+1]==0)k=1;
	}
	if(tot[k]==0)tot[k]=tt;
	else if(tt!=tot[k])f=false;
	tt=tot[0]-tot[1];
	if(tot[0]==0 && tot[1]==0)tt=1;
	if(tt<mi || tt>ma)f=false;
	if(!f)printf("-1");else printf("%lld",tt);
    return 0;
}