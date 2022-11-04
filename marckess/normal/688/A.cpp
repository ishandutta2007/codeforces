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

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, d, acu = 0, res = 0;
	string s;

	cin >> n >> d;
	while (d--) {
		cin >> s;

		bool x = 1;
		for (char c : s) {
			x &= c == '1';
		}

		if (!x)
			acu++;
		else
			acu = 0;

		res = max(res, acu);
	}

	cout << res << endl;

	return 0;
}