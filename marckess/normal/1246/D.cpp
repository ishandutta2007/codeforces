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

const int MX = 100005;
int n, p[MX], lvl[MX], sig[MX], ind;
set<int> st[MX];
vi res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> p[i];
		lvl[i] = lvl[p[i]] + 1;
		st[p[i]].insert(i);
		if (lvl[i] > lvl[ind])
			ind = i;
	}

	st[p[ind]].erase(ind);

	while (ind) {
		while (ind && st[p[ind]].empty()) {
			ind = p[ind];
			st[p[ind]].erase(ind);
		}
		if (!ind) break;

		int a = *st[p[ind]].begin();
		while (st[a].size()) {
			st[p[a]].erase(a);
			res.pb(ind);
			p[ind] = a;
			a = *st[a].begin();
		}

		st[p[a]].erase(a);
		res.pb(ind);
		p[ind] = a;
		ind = a;
	}

	for (int i = 1; i < n; i++)
		sig[p[i]] = i;

	for (int i = 0, j = 0; i < n; i++, j = sig[j])
		cout << j << " ";
	cout << endl;

	reverse(all(res));
	cout << res.size() << endl;
	for (int x : res)
		cout << x << " ";
	cout << endl;

	return 0;
}