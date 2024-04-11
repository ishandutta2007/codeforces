#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, a;
	vi c(1005);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		c[a]++;
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		bool f = 0;
		for (int j = 0; j <= 1000; j++) {
			if (c[j]) {
				if (f)
					res++;
				c[j]--;
				f = 1;
			}
		}
	}

	cout << res << endl;

	return 0;
}