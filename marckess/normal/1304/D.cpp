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
typedef vector<ii> vii;

const int MX = 200005;
int n, res[MX];
string s;

void solve () {
	cin >> n >> s;
	res[n] = 0;

	int act = 1;
	for (int i = n - 1; i >= 0; i--, act++) {
		res[i] = act;

		while (i && s[i - 1] == '<') {
			i--;
			res[i] = act;
		}

		for (int j = i + 1, p = act; j < n && res[j] == p; j++)
			res[j] = ++act;
	}

	for (int i = 0; i < n; i++)
		cout << res[i] << " ";
	cout << endl;

	act = 1;
	for (int i = 0; i < n; i++, act++) {
		res[i] = act;

		while (i + 1 < n && s[i] == '>') {
			i++;
			res[i] = act;
		}

		for (int j = i - 1, p = act; j >= 0 && res[j] == p; j--)
			res[j] = ++act;
	}

	for (int i = 0; i < n; i++)
		cout << res[i] << " ";
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}