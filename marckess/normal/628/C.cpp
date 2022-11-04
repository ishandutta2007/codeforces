#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

string s, t;
int n, k;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k >> s;
	t.resize(n);

	for (int i = 0; i < n; i++) {
		if (s[i] - 'a' > 'z' - s[i]) {
			if (s[i] - 'a' > k) {
				t[i] = s[i] - k;
				k = 0;
			} else {
				t[i] = 'a';
				k -= s[i] - 'a';
			}
		} else {
			if ('z' - s[i] > k) {
				t[i] = s[i] + k;
				k = 0;
			} else {
				t[i] = 'z';
				k -= 'z' - s[i];
			}
		}
	}

	if (k) cout << -1 << endl;
	else cout << t << endl;

	return 0;
}