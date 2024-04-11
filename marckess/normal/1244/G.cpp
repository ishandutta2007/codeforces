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

const int MX = 1000005;
int n, p[MX], q[MX];
ll k, _k;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	_k = k;
	for (int i = 1; i <= n; i++) {
		p[i] = q[i] = i;
		k -= i;
	}

	if (k < 0) {
		cout << -1 << endl;
		return 0;
	}

	int i = 1, j = n;
	while (i < j && k) {
		while (p[j] - p[i] > k)
			i++;
		int x = p[j] - p[i];
		k -= x;
		swap(p[i], p[j]);
		i++, j--;
	}

	cout << _k - k << endl;
	forn(i, n) cout << p[i+1] << " ";
	cout << endl;
	forn(i, n) cout << q[i+1] << " ";
	cout << endl;

	return 0;
}