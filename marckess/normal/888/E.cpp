#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 35;
int n, m, a[MX];
vi x, y;

void obtPart (int l, int r, vi &v) {
	for (int i = 0; i < (1 << (r - l + 1)); i++) {
		int acu = 0;
		for (int j = 0; j < r - l + 1; j++)
			if (i & (1 << j))
				acu = (acu + a[l+j]) % m;
		v.push_back(acu);
	}

	sort(ALL(v));
}

int obtRes () {
	int i = 0, j = y.size() - 1, res = 0;

	for (int i = 0; i < x.size(); i++) {
		while (j > 0 && x[i] + y[j] >= m)
			j--;
		res = max(res, x[i] + y[j]);
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	if (n > 20) {
		obtPart(0, n / 2, x);
		obtPart(n / 2 + 1, n - 1, y);

		cout << obtRes() << endl;
	} else {
		obtPart(0, n - 1, x);
		cout << x.back() << endl;
	}

	return 0;
}