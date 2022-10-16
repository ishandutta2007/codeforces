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

const int N = 2005;

int n, d[N];

bool st[N];

vector<PII> e;

void inline fd() {
	for (int i = 1; i <= n; i++) {
		if (d[i] != 2) continue;
		for (int j = i + 2; j <= n; j++) {
			if (d[j] != 2) continue;
			if (i == 1 && j == n) continue;
			d[i]++, d[j]++;
			e.pb(mp(i, j));
			return;
		}
	}
}

int main() {
	st[1] = 1;
	for (int i = 2; i < N; i++) {
		if (!st[i]) {
			for (int j = i + i; j < N; j += i) st[j] = 1;
		}
	}
	read(n);
	for (int i = 1; i <= n; i++) d[i] = 2;
	for (int i = 1; i < n; i++) e.pb(mp(i, i + 1));
	e.pb(mp(n, 1));
	while (st[e.size()]) {
		fd();
	}
	cout << e.size() << endl;
	for (PII o: e) cout << o.fi << " " << o.se << endl;
    return 0;
}