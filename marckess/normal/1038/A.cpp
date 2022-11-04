#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

string s;
int a, k, mn = 1e9, acu[256];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> a >> k >> s;

	for (char c : s) acu[c]++;

	for (int i = 'A'; i < 'A' + k; i++)
		mn = min(mn, acu[i]);

	cout << mn * k << endl;

	return 0;
}