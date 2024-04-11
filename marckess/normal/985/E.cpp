#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 500005;

struct BIT {
	int ft[MX];

	void update (int i, int k) {
		while (i < MX) {
			ft[i] += k;
			i += i & -i;
		}
	} 

	int getSum (int i) {
		int sum = 0;

		while (i) {
			sum += ft[i];
			i -= i & -i;
		}

		return sum;
	}

	int query (int a, int b) {
		return getSum(b) - getSum(a-1);
	}
};

int n, k, d, a[MX];
BIT ft;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k >> d;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n);

	for (int i = n - k; i >= 0; i--) {
		int j = upper_bound(a, a+n, a[i] + d) - a;

		if (j == n) {
			ft.update(i+1, 1);
		} else if (i + k <= j) {
			if (ft.query(i + k + 1, j + 1))
				ft.update(i + 1, 1);
		}
	}

	if (ft.query(1, 1))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}