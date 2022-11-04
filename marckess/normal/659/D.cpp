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
	
	int n, x[1005], y[1005], a;

	cin >> n;
	for (int i = 0; i <= n; i++)
		cin >> x[i] >> y[i];

	if (x[n-1] > x[0])
		a = 3;
	else
		a = 1;

	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (a == 0) {
			if (x[i] > x[i-1]) {
				a = 1;
			} else {
				a = 3;
				res++;
			}
		} else if (a == 1) {
			if (y[i] < y[i-1]) {
				a = 2;
			} else {
				a = 0;
				res++;
			}
		} else if (a == 2) {
			if (x[i] < x[i-1]) {
				a = 3;
			} else {
				a = 1;
				res++;
			}
		} else {
			if (y[i] > y[i-1]) {
				a = 0;
			} else {
				a = 2;
				res++;
			}
		}
	}
	cout << res << endl;

	return 0;
}