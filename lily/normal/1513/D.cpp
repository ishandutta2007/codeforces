#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define read(a) scanf("%d", &a)

const int N = 2e5 + 15;

int n, P;
int a[N], f[N], L[N], R[N];


int getf(int x) {
	return f[x] == x ? x : (f[x] = getf(f[x]));
}


void merge(int x, int y) {
	int cl = min(L[x], L[y]);
	int cr = max(R[x], R[y]);
	f[y] = x;
	L[x] = cl;
	R[x] = cr;
}

const int ll = 19;
int st[ll][N], LOG[N];

int get(int l, int r) {
	int le = LOG[r - l + 1];
	return __gcd(st[le][l], st[le][r - (1 << le) + 1]);
}

void work() {
	read(n); read(P);
	vector < pair<int, int> > V;
	for (int i = 1; i <= n; i++) read(a[i]), V.push_back({a[i], i});
	for (int i = 1; i <= n; i++) f[i] = L[i] = R[i] = i;

	for (int i = 1; i <= n; i++) st[0][i] = a[i];
	for (int i = 1; i < ll; i++) {
		for (int j = 1, x = 1 << (i - 1); j + (1 << i) - 1 <= n; j++) {
			st[i][j] = __gcd(st[i - 1][j], st[i - 1][j + x]);
		}
	}

	sort(V.begin(), V.end());

	LL ans = (n - 1ll) * P;
	for (auto o : V) {
		int v = o.first, i = o.second;
		if (v >= P) break;

		int l = 1, r = i;
		while (l < r) {
			int mid = (l + r) / 2;
			if (get(mid, i) == v) r = mid;
			else l = mid + 1;
		}
		int al = l;
		l = i, r = n;
		while (l < r) {
			int mid = (l + r + 1) / 2;
			if (get(i, mid) == v) l = mid;
			else r = mid - 1;
		}
		l = al;

		//cerr << i << " get : " << l <<" " << r << endl;

		for (int p = L[getf(i)] - 1; p >= l;  p = L[getf(i)] - 1) {
			ans -= P;
			ans += v;
			merge(getf(i), getf(p));
		}
		for (int p = R[getf(i)] + 1; p <= r;  p = R[getf(i)] + 1) {
			ans -= P;
			ans += v;
			merge(getf(i), getf(p));
		}
	
	}

	printf("%lld\n", ans);

}

int main() {
	LOG[0] = -1;
	for (int i = 1; i < N; i++) LOG[i] = LOG[i / 2] + 1;
	int T;
	read(T);
	while (T--) work();
}