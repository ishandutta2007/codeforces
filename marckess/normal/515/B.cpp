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

int gcd (int a, int b) {
	return b ? gcd(b, a%b) : a;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	bitset<105> bs;
	int n, m, k, x, d = 0;

	cin >> n >> m;
	d = gcd(n, m);

	cin >> k;
	while (k--) {
		cin >> x;
		bs[x%d] = 1;
	}
	cin >> k;
	while (k--) {
		cin >> x;
		bs[x%d] = 1;
	}

	if (bs.count() == d)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}