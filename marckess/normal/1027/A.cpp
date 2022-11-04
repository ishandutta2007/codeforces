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

int mv[256][2], t, n;
string s;

string obtRes () {
	for (int i = 0; i < n / 2; i++) {
		int f = 0;
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				f |= mv[s[i]][j] == mv[s[n-i-1]][k];
		if (!f) return "NO";
	}
	return "YES";
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for (int i = 'a'; i <= 'z'; i++) {
		mv[i][0] = i-1;
		mv[i][1] = i+1;
	}

	cin >> t;
	while (t--) {
		cin >> n >> s;
		cout << obtRes() << endl;
	}

	return 0;
}