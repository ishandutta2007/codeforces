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

const int MX = 200005;
int n, k, t[MX];
string s;
char res[MX];
vi v;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k >> s;

	if (n % 2 == 0) {
		int f = 1;
		for (int i = 0; i + 1 < n; i++)
			f &= s[i] != s[i+1];

		if (f) {
			for (int i = 0; i < n; i++)
				cout << "BW"[(s[i] == 'W') ^ bool(k % 2)];
			cout << endl;
			return 0;
		}
	}

	memset(t, -1, sizeof(t));
	for (int i = 0; i < n; i++)
		if (s[i] == s[MOD(i-1, n)] || s[i] == s[(i+1) % n]) {
			v.pb(i);
			t[i] = 0;
			res[i] = s[i];
		}

	for (int x : v) {
		if (s[x] != s[MOD(x - 1, n)]) {
			int ant = x;
			int cur = MOD(x - 1, n);

			for (int i = 1; i < n; i++) {
				if (t[cur] != -1 && t[cur] < i) break;
				res[cur] = "WB"[(res[ant] == 'B') ^ (i > k)];
				t[cur] = i;
				
				ant = cur;
				cur--;
				if (cur < 0) cur += n;
			}
		}

		if (s[x] != s[(x + 1) % n]) {
			int ant = x;
			int cur = (x + 1) % n;

			for (int i = 1; i < n; i++) {
				if (t[cur] != -1 && t[cur] < i) break;
				res[cur] = "WB"[(res[ant] == 'B') ^ (i > k)];
				t[cur] = i;

				ant = cur;
				cur++;
				if (cur >= n) cur -= n;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (t[i] != -1) cout << res[i];
		else cout << s[i];
	}
	cout << endl;

	return 0;
}