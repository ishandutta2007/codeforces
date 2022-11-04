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
const int maxn = 1e6+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int T , n , x , y , i , t;
char a[110];

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n;
		cin >> a+1;
		t = 0;
		for (i = 1 ; i <= n/2 ; i++)
		{
			x = a[i]-'a';
			y = a[n-i+1]-'a';
			if (x == y || x-1 == y+1 || x+1 == y-1) continue;
			t = 1;
		}
		if (t) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}