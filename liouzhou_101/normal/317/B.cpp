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

const int MaxN=70;

int n,t;
int F[110][110];

int main()
{
	cin>>n>>t;
	F[0][0]=n;
	while (1)
	{
		vector<pii> v;
		for (int i=0;i<=MaxN;++i)
			for (int j=0;j<=MaxN;++j)
				if (F[i][j]>=4)
					v.push_back(pii(i,j));
		if (v.empty()) break;
		for (int i=0;i<v.size();++i)
		{
			int x=v[i].X,y=v[i].Y;
			F[x][y]-=4;
			if (y) F[x][y-1]+=1;
			if (y==1) F[x][0]++;
			F[x][y+1]+=1;
			F[x+1][y]+=1;
			if (x) F[x-1][y]+=1;
			if (x==1) F[0][y]++;
		}
	}
	while (t--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if (x<0) x=-x;
		if (y<0) y=-y;
		if (x>MaxN||y>MaxN)
			puts("0");
		else
			printf("%d\n",F[x][y]);
	}
	return 0;
}