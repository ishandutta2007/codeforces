#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	res = n + 1;

	for (int i = max(1, (int)sqrt(n) - 10); i <= min(n, (int)sqrt(n) + 10); i++) {
		int b = (n + i - 1) / i;
		
		res = min(res, i + b);
	}
	cout << res << endl;

	return 0;
}