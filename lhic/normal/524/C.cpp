#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <queue>
#include <stack>
#include <bitset>
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define NAME ""

using namespace std;
	
typedef long long ll;
typedef long double ld;

const ld PI = acos(-1.0);

const int MAXN = 5001;
const int MK = 21;
const int INF = 1000 * 1000 * 1000 * 2 + 10;
int a[MAXN];
pair <int, int> b[MAXN * MK];

int main()
{
	int n, k;
	cin >> n >> k;
	b[0] = make_pair(0, 0);
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		for (int j = 1; j <= k; j++)
		{
			b[i * k + j] = make_pair(x * j, j);
		}
	}
	b[n * k + 1] = make_pair(INF, MK);
	sort(b, b + n * k + 1);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int x, ans = k + 1;
		cin >> x;
		for (int j = 0; j <= n * k; j++)
		{
			int id = lower_bound(b, b + n * k + 1, make_pair(x - b[j].first, 0)) - b;
			if (b[id].first + b[j].first == x)
			{
				ans = min(ans, b[id].second + b[j].second);
			}
		}
		if (ans > k) cout << -1 << endl;
		else cout << ans << endl;
	}
	return 0;
}