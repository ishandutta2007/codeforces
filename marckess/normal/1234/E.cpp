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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005;
int n, m, x[MX];
ll acu[MX], sa, sb, ca, cb;
vi pos;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> x[i];

	for (int i = 0; i + 1 < m; i++) {
		int a = x[i], b = x[i+1];
		if (a == b) continue;
		if (a > b) swap(a, b);
		
		acu[0] += b - a;
		
		acu[a] -= b - a;
		acu[a] += b - 1;

		acu[a+1] -= b - 1;
		acu[a+1] += b - (a + 1);

		acu[b] -= b - (a + 1);
		acu[b] += (a + 1) - 1;

		acu[b+1] -= (a + 1) - 1;
		acu[b+1] += (b + 1) - (a + 1);
	}

	for (int i = 1, j = 0; i <= n; i++) {
		acu[i] += acu[i-1];
		cout << acu[i] << " ";
	}
	cout << endl;

	return 0;
}