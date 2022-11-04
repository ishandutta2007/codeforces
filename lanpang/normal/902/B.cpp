#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 1e4+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , b[maxn];
vector <int> a[maxn]; 

int dfs(int p , int f , int ans)
{
	if (p == 1)
	{
		ans++;
	}
	else
	{
		if (b[f] != b[p])
		{
			ans++;
		}
	}
	int i;
	for (i = 0 ; i < a[p].size() ; i++)
	{
		ans = dfs(a[p][i],p,ans);
	}
	return ans;
}

int main ()
{
	int i , j;
	cin >> n;
	for (i = 2 ; i <= n ; i++)
	{
		scanf("%d",&j);
		a[j].push_back(i);
	}
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&b[i]);
	}
	cout << dfs(1,1,0) << "\n";
	//system("PAUSE");
	return 0;
}