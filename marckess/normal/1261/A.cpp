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

int n, k;
string s;
vii res;

void rev (int i, int j) {
	while (i < j) {
		swap(s[i], s[j]);
		i++, j--;
	}
}

void solve () {
	cin >> n >> k >> s;

	for (int i = 0; i < n;) {
		if (k > 1) {
			if (s[i] != '(') {
				int j = i+1;
				while (s[j] != '(')
					j++;
				res.emplace_back(i, j);
				rev(i, j);
			}
			if (s[i+1] != ')') {
				int j = i+1;
				while (s[j] != ')')
					j++;
				res.emplace_back(i+1, j);
				rev(i+1, j);
			}
			k--;
			i += 2;
		} else {
			if (s[i] != '(') {
				int j = i+1;
				while (j < n && s[j] != '(')
					j++;
				if (j == n) break;
				res.emplace_back(i, j);
				rev(i, j);
			}
			i++;
		}
	}

	cout << res.size() << endl;
	for (ii &r : res)
		cout << r.fi+1 << " " << r.se+1 << endl;
	res.clear();
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}