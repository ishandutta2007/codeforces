#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
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
const int maxn = 1e6+10;
const int inf = 0x3f3f3f3f;
const LL mod = 1e9+7;

int n , k , p[maxn];
LL a , b;

LL dfs(int l , int r , int x , int y)
{
	if (y-x+1 == 0) return a;
	if (r-l+1 == 1) return b*(y-x+1);
	int z;
	for (z = x ; z <= y ; z++)
		if (p[z] > (l+r)/2) break;
	LL ret1 = dfs(l,(l+r)/2,x,z-1);
	LL ret2 = dfs((l+r)/2+1,r,z,y);
	return min(ret1+ret2,b*(r-l+1)*(y-x+1));
}

int main()
{
	int i , j;
	cin >> n >> k >> a >> b;
	for (i = 1 ; i <= k ; i++)
		scanf("%d",&p[i]);
	sort(p+1,p+k+1);
	cout << dfs(1,(1<<n),1,k) << "\n";
	return 0;
}