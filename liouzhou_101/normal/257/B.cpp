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
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;

#define X first
#define Y second

const int MaxN=100010;

int solve(int n,int m)
{
	int x[]={n,m};
	int s=n+m;
	--x[0];
	int a=0,p=0;
	for (int i=2;i<=s;++i)
	{
		if (i&1)
		{
			if (x[p])
			{
				--x[p];
				++a;
			}
			else
			{
				p^=1;
				--x[p];
				--a;
			}
		}
		else
		{
			if (x[p^1])
			{
				p^=1;
				--x[p];
				--a;
			}
			else
			{
				--x[p];
				++a;
			}
		}
	}
	return a;
}

int main()
{
	int n,m;
	cin>>n>>m;
	int x=max(solve(n,m),solve(m,n));
	int a=(n+m-1+x)/2;
	int b=n+m-1-a;
	cout<<a<<" "<<b<<endl;
	return 0;
}