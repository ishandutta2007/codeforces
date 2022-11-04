#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int n, res = 0;

int f(int n) {
	int res = n;
	while (n){
		res += n % 10;
		n /= 10;
	}
	return res;
}

vi r;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = max(1, n-100); i <= n; i++) {
		if (f(i)==n) r.pb(i);
	}
	
	cout << r.size() << endl;
	for (int x : r) cout << x << " ";
	cout << endl;

	return 0;
}