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

const int MX = 1005;
int n, k, a, b, c, d;
bitset<MX> bs;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k >> a >> b >> c >> d;

	bs[a] = 1;
	bs[b] = 1;
	bs[c] = 1;
	bs[d] = 1;

	if (n == 4 || k < n + 1) {
		cout << -1 << endl;
		return 0;
	}

	cout << a << " " << c << " ";
	for (int i = 1; i <= n; i++)
		if (!bs[i])
			cout << i << " ";
	cout << d << " " << b << endl;

	cout << c << " " << a << " ";
	for (int i = 1; i <= n; i++)
		if (!bs[i])
			cout << i << " ";
	cout << b << " " << d << endl;

	return 0;
}