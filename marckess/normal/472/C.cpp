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
	
	int n, p[100005];
	string a[100005], b[100005], x(1, 'a'-1);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		if (a[i] > b[i])
			swap(a[i], b[i]);
	}
	for (int i = 0; i < n; i++)
		cin >> p[i];

	for (int i = 0; i < n; i++) {
		int u = p[i];

		if (a[u] < x) {
			if (b[u] < x) {
				cout << "NO" << endl;
				return 0;
			}
			x = b[u];
		} else {
			x = a[u];
		}
	}

	cout << "YES" << endl;

	return 0;
}