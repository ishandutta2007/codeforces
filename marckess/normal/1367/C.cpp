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

const int MX = 55;
int n, k, res;
string s, t;

void solve () {
	cin >> n >> k >> s;
	t = s;

	for (int i = 0; i < n; i++)
		if (t[i] == '1') {
			for (int j = i - k; j <= i + k; j++)
				if (0 <= j && j < n)
					s[j] = '1';
		}

	res = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == '0') {
			res++;
			for (int j = i + 1; j <= i + k; j++)
				if (j < n)
					s[j] = '1';
		}
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}