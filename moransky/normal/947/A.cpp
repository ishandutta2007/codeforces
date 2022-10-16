// xtqqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e6 + 5;

bool st[N];

vector<int> d[N];

int x, c[N], L = 1e6, ans = 2e9;

void upd(int v) {
	for (int t: d[v])
		chkMin(ans, v - t + 1);
}

int main() {
	for (int i = 2; i <= L; i++) {
		if (!st[i]) {
			for (int j = i + i; j <= L; j += i) d[j].pb(i);
			for (int j = i + i; j <= L; j += i) st[j] = 1;	
		}
	}
	read(x);
	for (int v: d[x]) {
		c[x - v + 1]++;
		c[x + 1]--;
	}
	for (int i = 1; i <= L; i++) {
		c[i] += c[i - 1];
		if (c[i]) upd(i);
	}
	printf("%d\n", ans);
    return 0;
}