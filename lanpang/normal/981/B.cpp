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

int n , i , x , y;
map <int,int> a;
LL ans;

int main()
{
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d%d",&x,&y);
		a[x] = max(a[x],y);
	}
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d%d",&x,&y);
		a[x] = max(a[x],y);
	}
	map <int,int> ::iterator it;
	for (it = a.begin() ; it != a.end() ; it++)
	{
		ans += (LL)it->second; 
	}
	cout << ans << "\n";
	return 0;
}