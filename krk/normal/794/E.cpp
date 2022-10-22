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

const int Maxn = 300005;

int n;
int a[Maxn];
int mx[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	if (n == 1) { printf("%d\n", a[0]); return 0; }
	for (int i = 0; i < n; i++) {
		if (i + 1 < n) {
			int got = 2 + 2 * min(i, n - i - 2);
			mx[got] = max(mx[got], a[i]);
		}
		if (i - 1 >= 0) {
			int got = 2 + 2 * min(i - 1, n - i - 1);
			mx[got] = max(mx[got], a[i]);
		}
		mx[1] = max(mx[1], a[i]);
		if (i - 1 >= 0 && i + 1 < n) {
			int el = max(min(a[i - 1], a[i]), min(a[i], a[i + 1]));
			int got = 3 + 2 * min(i - 1, n - i - 2);
			mx[got] = max(mx[got], el);
		}
	}
	for (int i = n; i >= 2; i--)
		mx[i - 2] = max(mx[i - 2], mx[i]);
	for (int i = 0; i < n; i++)
		printf("%d%c", mx[n - i], i + 1 < n? ' ': '\n');
	return 0;
}