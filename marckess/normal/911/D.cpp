#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define fill_to_n(a,n,k) iota(a,a+n,k)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, a[1505], m, l, r, f = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				f = 1 - f;
			}
		}
	}

	cin >> m;
	while (m--) {
		cin >> l >> r;

		int x = r - l + 1;
		if ((x * (x - 1) / 2) % 2)
			f = 1 - f;

		cout << (f ? "odd" : "even") << endl;
	}

	return 0;
}