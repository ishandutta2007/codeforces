#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 150005;
int n, s[MX], ex[MX];
set<int> st;

void no () {
	cout << 0 << endl;
	exit(0);
}

bool valid (int i) {
	if (0 <= i && i + 1 < n) {
		if (i % 2 == 0 && s[i] >= s[i+1])
			return 0;

		if (i % 2 == 1 && s[i] <= s[i+1])
			return 0;
	}

	return 1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn(i, n) cin >> s[i];

	for (int i = 0; i + 1 < n; i++)
		if (!valid(i)) {
			st.insert(i);
			st.insert(i + 1);
		}

	if (st.size() > 8) no();

	int res = 0;

	for (int x : st) {
		ex[x] = 1;

		for (int i = 0; i < n; i++)
			if (!ex[i]) {
				int f = 1;
				swap(s[x], s[i]);

				for (int y : st) {
					f &= valid(y);
					f &= valid(y - 1);
				}

				f &= valid(i);
				f &= valid(i - 1);
				res += f;

				swap(s[x], s[i]);
			}
	}

	cout << res << endl;

	return 0;
}