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



int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, res = 1e9;
	string s;

	cin >> n >> s;

	for (int i = 0; i + 4 <= n; i++) {
		int a = abs(int(s[i]) - 'A');
		int b = abs(int(s[i+1]) - 'C');
		int c = abs(int(s[i+2]) - 'T');
		int d = abs(int(s[i+3]) - 'G');

		a = min(a, 26 - a);
		b = min(b, 26 - b);
		c = min(c, 26 - c);
		d = min(d, 26 - d);

		res = min(res, a+b+c+d);
	}

	cout << res << endl;
	
	return 0;
}