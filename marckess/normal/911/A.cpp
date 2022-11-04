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
	
	int n;

	cin >> n;

	vi v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	int d = *min_element(v.begin(), v.end()), mn = 1e9, ant = -1e9;

	for (int i = 0; i < n; i++) {
		if (v[i] == d) {
			mn = min(mn, i - ant);
			ant = i;
		}
	}

	cout << mn << endl;

	return 0;
}