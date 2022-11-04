#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

const int MX = 200005;
int n, res[MX], sz;
list<ii> ls;
list<ii>::iterator it[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, 2 * n) {
		char c;
		int x;
		cin >> c;
		if (c == '+') {
			ls.insert(ls.end(), ii(0, ++sz));
		} else {
			cin >> x;
			it[x] = ls.insert(ls.end(), ii(1, x));
		}
	}
	for (int i = 1; i <= n; i++) {
		auto act = it[i];
		if (act == ls.begin()) {
			cout << "NO" << endl;
			return 0;
		}
		auto ant = act;
		ant--;
		if (ant->fi) {
			cout << "NO" << endl;
			return 0;
		}
		res[ant->se] = i;
		ls.erase(ant);
		ls.erase(act);
	}
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++) cout << res[i] << " ";
	cout << endl;
	
	return 0;
}