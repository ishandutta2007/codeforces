#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int x, y, z, t1, t2, t3;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> x >> y >> z >> t1 >> t2 >> t3;

	int a = abs(x-y) * t1;
	int b = abs(x-z) * t2 + abs(x-y) * t2 + 3 * t3;

	if (b <= a) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}