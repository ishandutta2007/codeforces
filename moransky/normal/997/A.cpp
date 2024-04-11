#include <bits/stdc++.h>

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

const int N = 3e5 + 5;

int n, x, y, cnt;

char a[N];

int main() {
	read(n), read(x), read(y);
	scanf("%s", a + 1);
	for (int i = 1; i <= n; i++) {
		if (a[i] == '1') continue;
		int j = i;
		while (j < n && a[j + 1] == '0') j++;
		i = j;
		cnt++;
	}
	if (cnt == 0) {
		puts("0"); return 0;
	}
	int A = 0;
	if (x < y) A = cnt - 1;
	printf("%lld\n", (LL)A * x + (LL)(cnt - A) * y);
}