#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=110;

int n,m;
string a,c;
int b,d;
pii p[MaxN];

int main()
{
	cin>>b>>d>>a>>c;
	n=a.size();
	m=c.size();
	for (int i=0;i<m;++i)
	{
		int x=0,y=i;
		for (int j=0;j<n;++j)
		{
			if (a[j]==c[y])
			{
				++y;
				if (y==m)
				{
					++x;
					y=0;
				}
			}
		}
		p[i]=pii(x,y);
	}
	int x=0,y=0;
	for (int i=1;i<=b;++i)
	{
		int px=x,py=y;
		px+=p[y].X;
		py=p[y].Y;
		x=px;
		y=py;
	}
	cout<<max(x/d,0)<<endl;
	return 0;
}