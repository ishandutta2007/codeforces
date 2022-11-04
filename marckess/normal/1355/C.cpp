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
 
const int MX = 1000005;
ll res = 0, acu[MX];
int a, b, c, d;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	cin >> a >> b >> c >> d;
 
	for (int i = a; i <= b; i++) {
		acu[i + b]++;
		acu[i + c + 1]--;
	}

	for (int i = 1; i < MX; i++)
		acu[i] += acu[i - 1];

	for (int i = 2 * d; i >= c; i--)
		acu[i] += acu[i + 1];

	for (int i = c; i <= d; i++)
		res += acu[i + 1];

	cout << res << endl;

	return 0;
}