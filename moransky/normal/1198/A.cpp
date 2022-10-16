#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long LL;

using namespace std;

template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }


template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 4e5 + 5;

int n, I, a[N];

LL K;

map<int, int> c;

int main() {
	read(n), read(I);
	for (int i = 1; i <= n; i++) read(a[i]);
	sort(a + 1, a + 1 + n);
	int k = 8 * I / n;
	K = 1;
	for (int i = 1; i <= k; i++) {
		 K *= 2;
		 if (K > 1e9) break;
	}
	int ans = 0;
	for (int i = 1, j = 1; i <= n; i++) {
		c[a[i]]++;
		while (c.size() > K) {
			c[a[j]]--;
			if (c[a[j]] == 0) c.erase(a[j]);
			j++;
		}
		chkMax(ans, i - j + 1);
	}
	printf("%d\n", n - ans);
}