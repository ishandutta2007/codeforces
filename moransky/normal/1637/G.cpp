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

const int N = 1e5 + 5;

int n, a[N];

vector<PII> ret;

int inline ism(int x) {
	return (x & -x) == x;
}

bool inline chk() {
	for (int i = 1; i <= n; i++) if (!ism(a[i])) return 0;
	return 1;
}

void inline solve() {
	for (int i = 1; i <= n; i++) a[i] = i;
	int v = 1; ret.clear();
	while (v < n) v <<= 1;
	int la = n;
//	for (int i = v; i >= 2; i /= 2) {
//		if (i > la) continue;
//		int t = la - i;
//		for (int j = 1; j <= t; j++) {
//			ret.pb(mp(i + j, i - j));
//			a[i + j] = 2 * i, a[i - j] = 2 * j;
//		}
//		la = i - t - 1;
//	}
	
//	for (int i = 1; i <= n; i++) cout << a[i] << endl;
//		puts("f");
	
	while (1) {
		if (chk()) break;
		
		sort(a + 1, a + 1 + n);
		for (int i = 1, j = n; i <= j; j--) {
			while (i <= j && (a[j] & -a[j]) == a[j]) j--;
			if (i > j) break;
			while (i <= j && !ism(a[i] + a[j])) i++;
			if (i > j) break;
			assert(i <= j);
			ret.pb(mp(a[i], a[j]));
			int A = a[i] + a[j], B = a[j] - a[i];
			a[i] = A, a[j] = B;
			
			i++;
		}
	}
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; i++) {
		if (a[i] && a[i - 1] == a[i] && a[i] != v) {
			ret.pb(mp(a[i], a[i]));
			a[i] *= 2, a[i - 1] = 0;
		}
	}
	for (int w = 1; w < v; w <<= 1) {
		sort(a + 1, a + 1 + n);
		int c = 0, p = -1;
		for (int i = 1; i <= n; i++) {
			if (a[i] == w) c++, p = i;
		}
		if (c == 0) continue;
		if (c & 1) {
			ret.pb(mp(w, 0));
			a[1] = w;
			sort(a + 1, a + 1 + n);
		}
		int la = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == w) {
				if (la) ret.pb(mp(w, w)), a[i] = w * 2, a[la] = 0, la = 0;
				else la = i;
			}
		}
	} 
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
		if (!a[i]) ret.pb(mp(0, v)), a[i] = v;
	for (int i = 1; i <= n; i++) {
		assert(a[i] == v);
	}
	assert(ret.size() <= 20 * n);
	printf("%lu\n", ret.size());
	for (auto o: ret) printf("%d %d\n", o.fi, o.se);
}

int main() {
	int T; read(T); 
	while (T--) {
		read(n);
		if (n == 2) puts("-1");
		else {
			solve();
		}
	}
    return 0;
}