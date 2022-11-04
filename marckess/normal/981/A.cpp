#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int res = 0;
string s;

bool esPal (int i, int j) {
	while (i < j) {
		if (s[i] != s[j]) return 0;
		i++, j--;
	}
	return 1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s;
	for (int i = 0; i < s.size(); i++)
		for (int j = i; j < s.size(); j++)
			if (!esPal(i, j))
				res = max(res, j-i+1);
	cout << res << endl;

	return 0;
}