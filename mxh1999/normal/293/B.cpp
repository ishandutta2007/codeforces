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

#define maxn 20
const int mo=1000000007;
int a[maxn][maxn];
int n,m,k;
int num[maxn];
int now[maxn][maxn];
int L[2016];
int c[maxn];

int mjy;

//#define lowbit(i)	(i&(-i))
int search(int x,int y)
{
	if (y>m)	x++,y=1;
	if (x>n)	return 1;
	int mjy=0,last=-1;
	now[x][y]=now[x-1][y]|now[x][y-1];
	int leave=((1<<k)-1)-now[x][y];
	if (a[x][y])
	{
		if (c[a[x][y]]&leave)
		{
			now[x][y]|=c[a[x][y]];
			num[a[x][y]]++;
			mjy=search(x,y+1);
			now[x][y]^=c[a[x][y]];
			num[a[x][y]]--;
		}
    }	else
	for (;leave;leave-=leave&(-leave))
	{
		int low=leave&(-leave);
		now[x][y]|=low;
		int xmm=L[low];
		num[xmm]++; 
		if (num[xmm]==1)
		{
			if (last==-1) last=search(x,y+1);
			mjy=(mjy+last)%mo;
		}
		else mjy=(mjy+search(x,y+1))%mo;
		now[x][y]^=low;
		num[xmm]--;
	}
	return mjy;
}
int main()
{
	//freopen("path.in","r",stdin);
	//freopen("path.out","w",stdout);
	read(n),read(m),read(k);
	if (n+m-1>k)
	{
		printf("0\n");
		return 0;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			read(a[i][j]);
			if (a[i][j])	num[a[i][j]]++;
		}
	for (int i=1;i<=k;i++)	L[1<<i-1]=i,c[i]=1<<i-1;
	mjy=search(1,1);
	printf("%d\n",mjy);
	return 0;
}