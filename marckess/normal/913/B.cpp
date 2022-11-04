#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int n, p[1005], c[1005] = {0}, l[1005] = {0};

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		c[p[i]]++;
	}

	for (int i = 1; i <= n; i++) {
		if (c[i] == 0) {
			l[p[i]]++;
		}
	}

	for (int i = 1; i <= n; i++ ) {
		if (c[i] && l[i] < 3) {
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;

	return 0;
}