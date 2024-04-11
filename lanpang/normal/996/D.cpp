#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , a[210] , ans;
vector <int> b[110];

void seta()
{
	int i;
	for (i = 1 ; i <= n ; i++)
	{
		b[i].clear();
	}
	for (i = 1 ; i <= n*2 ; i++)
	{
		b[a[i]].push_back(i);
	}
	for (i = 1 ; i <= n ; i++)
	{
		if (b[i][0] > b[i][1]) swap(b[i][0],b[i][1]);
	}
}

int main()
{
	int i , j;
	cin >> n;
	for (i = 1 ; i <= n*2 ; i++)
	{
		cin >> a[i];
	}
	for (i = 1 ; i <= n*2 ; i += 2)
	{
		seta();
		if (b[a[i]][1] != i+1)
		{
			ans += b[a[i]][1]-b[a[i]][0]-1;
			for (j = b[a[i]][1]-1 ; j > b[a[i]][0] ; j--)
			{
				swap(a[j+1],a[j]);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}