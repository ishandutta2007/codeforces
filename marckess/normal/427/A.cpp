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
	
	int n, a = 0, res = 0, x;

	cin >> n;
	while (n--) {
		cin >> x;

		if (x == -1) {
			if (a) 
				a--;
			else
				res++;
		} else {
			a += x;
		}
	}

	cout << res << endl;

	return 0;
}