#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int Maxn = 1005;
const int Maxl = 26;
const int mod = 1000000007;

int n;
string s;
int a[Maxl];
int ways[Maxn], mx[Maxn], mn[Maxn];

int main() 
{
	scanf("%d", &n);
	cin >> s;
	for (int i = 0; i < Maxl; i++)
		scanf("%d", &a[i]);
	fill(ways, ways + Maxn, 0);
	fill(mx, mx + Maxn, 0);
	fill(mn, mn + Maxn, Maxn);
	ways[0] = 1; mx[0] = 0; mn[0] = 0;
	for (int i = 0; i < n; i++) {
		int lim = n;
		for (int j = i; j < min(lim, i + a[s[j] - 'a']); j++) {
			lim = min(lim, i + a[s[j] - 'a']);
			ways[j + 1] = (ways[j + 1] + ways[i]) % mod;
			mx[j + 1] = max(mx[j + 1], max(mx[i], j + 1 - i));
			mn[j + 1] = min(mn[j + 1], mn[i] + 1);
		}
	}
	printf("%d\n%d\n%d\n", ways[n], mx[n], mn[n]);
    return 0;
}