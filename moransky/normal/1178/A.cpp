// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 105;

int n, a[N];

int main() {
	read(n);
	int s = 0;
	for (int i = 1; i <= n; i++) read(a[i]), s += a[i];
	int ans = a[1];
	vector<int> v; v.pb(1);
	for (int i = 2; i <= n; i++)
		if (a[1] >= 2 * a[i]) ans += a[i], v.pb(i);
	if (2 * ans > s) {
		cout << v.size() << endl;
		for (int u: v) cout << u << " ";
	} else {
		puts("0");
	}
    return 0;
}