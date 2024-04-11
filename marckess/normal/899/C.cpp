#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	int n;
	cin >> n;

	ll sum = ll(n) * (n + 1) / 2, aux = 0;

	if (sum % 2)
		cout << 1 << endl;
	else
		cout << 0 << endl;

	sum /= 2;
	vi res;
	while (sum) {
		while (n > sum)
			n--;

		sum -= n;
		res.push_back(n);
		aux += n;
		n--;
	}

	cout << res.size() << " ";
	for (int x : res)
		cout << x << " ";
	cout << endl;

	return 0;
}