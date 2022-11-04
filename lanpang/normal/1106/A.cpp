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

int n , ans;
char a[510][510];

int main()
{
	int i , j;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
		cin >> a[i]+1;
	for (i = 2 ; i < n ; i++)
		for (j = 2 ; j < n ; j++)
			if (a[i][j] == 'X' && a[i+1][j+1] == 'X' && a[i+1][j-1] == 'X' && a[i-1][j+1] == 'X' && a[i-1][j-1] == 'X') 
				ans++;
	cout << ans << "\n";
	return 0;
}