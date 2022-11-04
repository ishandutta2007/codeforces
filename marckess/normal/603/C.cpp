#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int n, k, res;

int f (int n) {
	if (n == 0) return 0;
	if (n % 2 && n > 3) return 0;

	int x = f(n - 1);
	int y = n % 2 ? -1 : f(n / 2) * (k % 2);

	if (x != 0 && y != 0)
		return 0;

	if (x != 1 && y != 1)
		return 1;

	return 2;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;

	while (n--) {
		int a;
		cin >> a;
		res ^= f(a);
	}

	if (res)
		cout << "Kevin" << endl;
	else
		cout << "Nicky" << endl;

	return 0;
}