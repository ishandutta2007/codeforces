#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<queue>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=1010;

int k;
int tot;

int a[MaxN][MaxN];

void addedge(int x,int y)
{
	a[x][y]=a[y][x]=1;
}

int main()
{
	cin>>k;
	addedge(1,tot=3);
	for (int i=1;i<=28;++i)
	{
		addedge(tot,tot+1);
		++tot;
	}
	addedge(tot,2);
	for (int p=28;p>=0;--p)
		if (1<<p<=k)
		{
			k-=1<<p;
			int ax=1,ay=1,bx=1,by=1;
			for (int i=1;i<=p;++i)
			{
				ax=bx,ay=by;
				bx=++tot;
				by=++tot;
				addedge(ax,bx);
				addedge(ax,by);
				addedge(ay,bx);
				addedge(ay,by);
			}
			if (p==28) ax=2; else ax=p+4;
			addedge(bx,ax);
			addedge(by,ax);
		}
	cout<<tot<<endl;
	for (int i=1;i<=tot;++i)
	{
		for (int j=1;j<=tot;++j)
		{
			putchar(a[i][j]?'Y':'N');
		}
		puts("");
	}
	return 0;
}