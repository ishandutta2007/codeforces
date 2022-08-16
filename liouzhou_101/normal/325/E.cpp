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

int n;
int u[100010];

void DFS(int x)
{
	u[x]=1;
	if (x==1)
		printf("0 1");
	else
	{
		if (x%2)
		{
			if (u[(n+x-1)/2])
				DFS((x-1)/2);
			else
				DFS((n+x-1)/2);
		}
		else
		{
			if (u[(n+x)/2])
				DFS(x/2);
			else
				DFS((n+x)/2);
		}
		printf(" %d",x);
	}
}

int main()
{
	cin>>n;
	if (n%2)
	{
		puts("-1");
		return 0;
	}
	DFS(0);
	return 0;
}