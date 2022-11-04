#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

typedef unsigned ui;

const int MX = 100'000'010;
bitset<MX> bs;
ui n, a, b, c, d, res = 0;

void add (ui x) {
	ui t = 0, y = x;

	while (1) {
		t += n / y;
		if (y <= (n + x - 1) / x) y *= x;
		else break;
	}

	res += t * (((a * x + b) * x + c) * x + d);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> a >> b >> c >> d;

	if (n >= 2) add(2);
	if (n >= 3) add(3);

	for (ui i = 5, d = 2; i <= n; i += d, d = 6 - d) {
		if (!bs[i/3]) {
			add(i);
			if (i <= (n + i - 1) / i)
			    for (ui j = i * i, e = d; j <= n; j += e * i, e = 6 - e)
				    bs[j/3] = 1;
		}
	}

	cout << res << endl;

	return 0;
}