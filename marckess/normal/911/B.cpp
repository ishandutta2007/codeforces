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
	
	int n, a, b, res = 0;

	cin >> n >> a >> b;

	for (int i = 1; i <= min(a, b); i++) {
		if (a / i + b / i >= n) {
			res = i;
		}
	}

	cout << res << endl;

	return 0;
}