// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5;

int a[N], b[N], c[N], n;

bool inline chk() {
	int k = 1, z = 1;
	for (int i = 1; i <= n; i++) {
		int j = i;
		while (j < n && b[j + 1] == b[i]) j++;
		int t = j - i + 1;
		bool o = 0;
		while (k <= n && (!o || c[b[i]] < t)) {
			c[a[k]]++;
			if (a[k] == b[i]) o = 1;
			k++;
		}
		if (!o) return 0;
		int u = k - 1;
		c[b[i]] -= t;
		i = j;
	}
	return 1;
}

int main() {
    int T; read(T);
    while (T--) {
    	read(n);
    	for (int i = 1; i <= n; i++) read(a[i]);
    	for (int i = 1; i <= n; i++) read(b[i]);
    	puts(chk() ? "YES" : "NO");
    	for (int i = 1; i <= n; i++) c[i] = 0;
    }
    return 0;
}