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
#define y1 y11
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define NAME ""

using namespace std;
	
typedef long long ll;
typedef long double ld;

const ld PI = acos(-1.0);

const int MAXN = 2000001;

int ans[MAXN];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	int n, q;
	scanf("%d%d", &n, &q);
	int g0 = 0, g1 = 1;
	for (int i = 0; i < q; i++)
	{
		int t;
		scanf("%d", &t);
		if (t == 1)
		{
			int x;
			scanf("%d", &x);
			g0 = (g0 + n + x) % n, g1 = (g1 + n + x) % n;
		}
		else
		{
			if (g0 % 2) g0--, g1++;
			else g0++, g1--;
		}
	}
	for (int i = 0; i < n / 2; i++)
	{
		ans[(g0 + 2 * i) % n] = 2 * i;
		ans[(g1 + 2 * i) % n] = 2 * i + 1;
	}
	for (int i = 0; i < n; i++) printf("%d ", ans[i] + 1);
	return 0;
}