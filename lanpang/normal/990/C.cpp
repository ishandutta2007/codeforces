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
const int maxn = 3e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

LL n , l , s[maxn] , ans , f[maxn*2] , mi;
string c[maxn];

int main()
{
	int i , j;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		cin >> c[i];
		l = c[i].size();
		mi = 300000;
		for (j = 0 ; j < l ; j++)
		{
			if (c[i][j] == '(') s[j+1] = s[j]+1;
			else s[j+1] = s[j]-1;
			mi = min(mi,s[j+1]);
		}
		if (mi == s[l] && mi <= 0)
		{
			f[mi+300000]++;
		}
	}
	for (i = 1 ; i <= n ; i++)
	{
		l = c[i].size();
		mi = 300000;
		for (j = 0 ; j < l ; j++)
		{
			if (c[i][j] == '(') s[j+1] = s[j]+1;
			else s[j+1] = s[j]-1;
			mi = min(mi,s[j+1]);
		}
		if (mi >= 0)
		{
			ans += f[300000-s[l]];
		}
	}
	cout << ans << "\n";
	return 0;
}