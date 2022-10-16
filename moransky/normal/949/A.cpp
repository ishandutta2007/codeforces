// MoRanSky
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> void inline read(T &x) {
	x = 0; int f = 1; char s = getchar();
	while (s > '9' || s < '0') { if (s == '-') f = -1; s = getchar(); }
	while (s >= '0' && s <= '9') x = x * 10 + (s ^ 48), s = getchar();
	x *= f;
}

template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }
template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }

const int N = 2e5 + 5;

int n;

char s[N];

int t;

vector<int> e[N], d[2];

void inline work() {
	for (int i = 1; i <= n; i++) {
		if (s[i] == '1'){
			if (!d[0].size()) {
				puts("-1");
				return;
			}
			int u = d[0].back(); d[0].pop_back();
			e[u].pb(i);
			d[1].pb(u);
		} else {
			if (d[1].size()) {
				int u = d[1].back(); d[1].pop_back();
				e[u].pb(i);
				d[0].pb(u);
			} else {
				e[++t].pb(i);
				d[0].pb(t);
			}
		}
	}
	if (d[1].size()) {
		puts("-1");
		return;
	}
	printf("%d\n", t);
	for (int j = 1; j <= t; j++) {
		printf("%lu ", e[j].size());
		for (int v: e[j]) printf("%d ", v);
		puts("");
	}
}

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	work();
}