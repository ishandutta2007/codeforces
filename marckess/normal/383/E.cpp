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

const int MX = (1 << 24) + 5;
int n, mem[MX];
ll res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	while (n--) {
		string s;
		cin >> s;

		int mk = 0;
		for (char c : s)
			mk |= (1 << c - 'a');

		for (int i = mk; i; i = (i - 1) & mk) {
			if (__builtin_popcount(i) & 1) mem[i]++;
			else mem[i]--;
		}
	}

	forn (j, 24)
		for (int i = (1 << 24) - 1; i >= 0; i--)
			if (~i & (1 << j))
				mem[i | (1 << j)] += mem[i];

	forn (i, (1 << 24))
		res ^= 1ll * mem[i] * mem[i];

	cout << res << endl;

	return 0;
}