#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, a, c[10] = {0}, k;
	char h;

	cin >> n;
	while (n--) {
		cin >> h;
		a = h - '0';

		for (int i = 2; i <= a; i++) {
			for (int j = 2, k = i; j <= i; j++) {
				while (k % j == 0) {
					c[j]++;
					k /= j;
				}
			}
		}
	}

	for (int a = 9; a > 1; a--) {
		while (c[a]) {
			cout << a;

			for (int i = 2; i <= a; i++) {
				for (int j = 2, k = i; j <= i; j++) {
					while (k % j == 0) {
						c[j]--;
						k /= j;
					}
				}
			}

		}
	}

	cout << endl;

	return 0;
}