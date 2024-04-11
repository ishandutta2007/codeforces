#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
int s[Maxn], g[Maxn];
int mx[Maxn];
ll res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &s[i], &g[i]);
	int cur = s[0] + g[0] - 1;
	for (int i = 0; i < n; i++) {
		cur = min(cur + 1, s[i] + g[i]);
		mx[i] = cur;
	}
	cur = s[n - 1] + g[n - 1] - 1;
	for (int i = n - 1; i >= 0; i--) {
		cur = min(cur + 1, s[i] + g[i]);
		mx[i] = min(mx[i], cur);
	}
	for (int i = 0; i < n; i++)
		if (mx[i] < s[i]) { printf("-1\n"); return 0; }
		else res += mx[i] - s[i];
	cout << res << endl;
	for (int i = 0; i < n; i++)
		printf("%d%c", mx[i], i + 1 < n? ' ': '\n');
	return 0;
}