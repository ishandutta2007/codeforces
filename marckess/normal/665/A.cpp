#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int a, ta, b, tb, x, y, res;
char c;
bitset<MX> bs;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> a >> ta >> b >> tb >> x >> c >> y;
	x = 60 * x + y;

	for (int i = 5 * 60; i < 24 * 60; i += b)
		bs[i] = 1;

	for (int i = max(0, x - tb + 1); i < min(24 * 60, x + ta); i++)
		res += bs[i];
	cout << res << endl;

	return 0;
}