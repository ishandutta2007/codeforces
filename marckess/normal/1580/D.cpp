
// Problem : D. Subsequence
// Contest : Codeforces - Codeforces Round #745 (Div. 1)
// URL : https://codeforces.com/contest/1580/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 4005;
int n, m, a[MX];

vi f (int i, int j) {
	if (i > j) return {0};
	
	int ind = i;
	for (int k = i; k <= j; k++)
		if (a[k] < a[ind])
			ind = k;
	
	vi izq = f(i, ind - 1);
	vi der = f(ind + 1, j);
	vi res(j - i + 2, -1e18);
	
	forn (x, izq.size()) forn (y, der.size()) {
		res[x + y] = max(
			res[x + y],
			izq[x] + der[y] - 2ll * x * y * a[ind]
		);
		
		res[x + y + 1] = max(
			res[x + y + 1],
			izq[x] + der[y] - 2ll * (x * y + x + y) * a[ind] + ll(m - 1) * a[ind]
		);
	}
	
	return res;
}

void main_() {
	cin >> n >> m;
	forn (i, n)
		cin >> a[i];
	
	cout << f(0, n - 1)[m] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}