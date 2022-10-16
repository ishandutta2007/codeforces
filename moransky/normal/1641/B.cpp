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

const int N = 505;

int n, a[N * N * 3];

map<int, int> M;

vector<PII> r;
vector<int> f;

void inline work() {
	int p = 1;
	while (p <= n) {
		int q = -1;
		for (int i = p + 1; i <= n; i++) {
			if (a[i] == a[p]) {
				q = i;
				break;
			}
		}
		int o = q - p - 1, ne = (q - p - 1) * 2;
		for (int i = n + ne; i >= q + 1 + ne; i--) a[i] = a[i - ne];
		n += ne;
		for (int i = 1; i <= o; i++) {
			a[q + i] = a[p + i];
			a[q + o + (o - i + 1)] = a[p + i];
			r.pb(mp(q + i - 1, a[p + i]));
		}
		int len = q - p;
		f.pb(2 * len);
		p += 2 * len;
	}
	cout << r.size() << endl;
	for (auto o: r) cout << o.fi << " " << o.se << endl;
	cout << f.size() << endl;
	for (int v: f) cout << v << " ";
	cout << endl;
}

int main() {
	int T; read(T);
	while (T--) {
		r.clear();
		f.clear();
		read(n);
		M.clear();
		for (int i = 1; i <= n; i++) read(a[i]), M[a[i]]++;
		bool op = 1;
		for (auto o: M)
			if (o.se & 1) op = 0;
		if (!op) {
			puts("-1");
			continue;
		}
		work();
	}
    return 0;
}