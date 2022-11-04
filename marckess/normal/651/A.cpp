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
	
	int a, b, res = 0;

	cin >> a >> b;
	while (a > 0 && b > 0) {
		if (a < b) {
			a += 1;
			b -= 2;
		} else {
			a -= 2;
			b += 1;
		}

		if (a >= 0 && b >= 0)
			res++;
	}

	cout << res << endl;

	return 0;
}