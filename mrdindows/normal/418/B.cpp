#include <bits/stdc++.h>
using namespace std;
#define INF 1100000000000000000
long long d[1<<21];
struct F {
	int x=0;
	int zad=0;
	int kol=0;
};
F f[110];

bool cmp(F a, F b) {
	if (a.kol<b.kol) return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	for (int i=1; i<(1<<21); i++) d[i]=INF;
	int n, m;
	long long b;
	cin >> n >> m >> b;
	for (int i=0; i<n; i++) {
		cin >> f[i].x >> f[i].kol;
		int k;
		cin >> k;
		while (k--) {
			int t;
			cin >> t;
			t--;
			f[i].zad|=(1<<t);
		}
	}
	sort(f, f+n, cmp);
	long long ans=d[(1<<m)-1];
	for (int i=0; i<n; i++) {
		for (int mask=0; mask < (1<<m); mask++) {
			d[mask|f[i].zad]=min(d[mask|f[i].zad], d[mask]+f[i].x+0LL);
		}
		ans=min(ans, d[(1<<m)-1]+1LL*f[i].kol*b);
	}
	if (d[(1<<m)-1]==INF) {
		cout << "-1\n";
		return 0;
	}
	cout << ans << endl;
	return 0;
}