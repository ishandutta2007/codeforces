#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )
#define LSB(S) (S & (-S))

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, a, b, res = 0, c = 0, x;
	cin >> n >> a >> b;
	while (n--) {
		cin >> x;
		if (x == 1) {
			if (a)
				a--;
			else if (b) {
				b--;
				c++;
			} else if (c)
				c--;
			else
				res++;
		} else {
			if (b)
				b--;
			else
				res += 2;
		}
	}

	cout << res << endl;

	return 0;
}