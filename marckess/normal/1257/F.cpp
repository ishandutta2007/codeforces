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
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 105;
int n, in[MX], sig[(1 << 15) * MX][33], mp[(1 << 15) * MX], sz; 

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> in[i];

	for (int i = 0; i < (1 << 15); i++) {
		int t = 0;

		for (int j = 0; j < n; j++) {
			int x = __builtin_popcount((in[j] ^ i) & ((1 << 15) - 1));

			if (!sig[t][x])
				sig[t][x] = ++sz;
			t = sig[t][x];
		}

		mp[t] = i;
	}

	for (int i = 0; i < (1 << 15); i++) {
		int mk = i << 15;

		for (int k = 0; k <= 30; k++) {
			int t = 0;

			for (int j = 0; j < n; j++) {
				int x = k - __builtin_popcount((in[j] ^ mk) & ~((1 << 15) - 1));
				
				if (x < 0 || !sig[t][x]) {
					t = 0;
					break;
				}
				t = sig[t][x];
			}

			if (t) {
				cout << mp[t] + mk << endl;
				return 0;
			}
		}
	}

	cout << -1 << endl;

	return 0;
}