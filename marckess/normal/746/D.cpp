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

	int k, n, a, b;

	cin >> n >> k >> a >> b;

	if (a == 0) {
		if (b > k)
			cout << "NO";
		else 
			for (int i = 0; i < b; i++)
				cout << "B";
	} else if (b == 0) {
		if (a > k)
			cout << "NO";
		else
			for (int i = 0; i < a; i++)
				cout << 'G';
	} else if (a >= b) {
		if (ceil(a / (b + 1.0)) > k)
			cout << "NO";
		else {
			for (int i = b; i >= 0; i--) {
				for (int j = a / (b + 1); j; j--)
					cout << "G";
				a -= a / (b + 1);
				if (b) {
					cout << "B";
					b--;
				}
			}
		}
	} else {
		if (ceil(b / (a + 1.0)) > k)
			cout << "NO";
		else {
			for (int i = a; i >= 0; i--) {
				for (int j = b / (a + 1); j; j--)
					cout << "B";
				b -= b / (a + 1);
				if (a) {
					cout << "G";
					a--;
				}
			}
		}
	}

	cout << endl;

	return 0;
}