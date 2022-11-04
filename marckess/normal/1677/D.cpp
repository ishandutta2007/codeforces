// Powered by CP Editor (https://cpeditor.org)

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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000005, mod = 998244353;
int n, k, v[MX];

void main_() {
	cin >> n >> k;
	forr (i, 1, n)
		cin >> v[i];
	
	for (int i = n - k + 1; i <= n; i++) {
		if (v[i] >= 1) {
			cout << 0 << endl;
			return;
		}
	}
	
	ll res = 1;
	for (int i = 1; i <= n - k; i++) {
		if (v[i] == 0) {
			(res *= k + 1) %= mod;
		} else if (v[i] == -1) {
			(res *= k + i) %= mod;
		}
	}
	
	for (int i = 2; i <= k; i++)
		(res *= i) %= mod;
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}