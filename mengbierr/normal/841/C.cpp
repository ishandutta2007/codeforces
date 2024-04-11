#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define MEM(a, x) memset(a, x, sizeof(a))
#define ALL(a) a.begin(), a.end()
#define UNIQUE(a) a.erase(unique(ALL(a)), a.end())
typedef long long ll;

int m, a[200005], c[200005];

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin >> m;
	FOR(i, m) cin >> a[i];
	vector<pair<int, int> > b(m);
	FOR(i, m) {
		cin >> b[i].first;
		b[i].second = i;
	}
	sort(a, a+m);
	sort(ALL(b));
	FOR(i, m) c[b[i].second] = a[m-i-1];
	FOR(i, m) {
		cout << c[i] << (i < m-1 ? " " : "\n");
	}
	return 0;
}