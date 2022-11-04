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

bitset<10000000> bs;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	bs.set();
	for (int i = 0; i <= 1e3; i++)
		bs[i*i] = 0;

	int n, a, res = -1e6;

	cin >> n;
	while (n--) {
		cin >> a;
		if (a < 0 || bs[a])
			res = max(res, a);
	}

	cout << res << endl;

	return 0;
}