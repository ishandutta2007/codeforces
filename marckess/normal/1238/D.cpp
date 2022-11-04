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

int n, sig[255];
string s;
ll res = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
		s[i] -= 'A';

	memset(sig, -1, sizeof(sig));
	for (int i = n - 1; i >= 0; i--) {
		if (i + 1 < n && s[i] == s[i+1]) {
			if (sig[1-s[i]] != -1)
				res += n - i - 2;
			else
				res += n - i - 1;
		} else {
			if (sig[s[i]] != -1) {
				res += n - sig[s[i]];
			}
		}
		sig[s[i]] = i;
	}

	cout << res << endl;

	return 0;
}