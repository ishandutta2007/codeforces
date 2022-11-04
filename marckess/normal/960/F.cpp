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

const int MX = 100005;
int n, m, res;
set<ii> st[MX];

int find (int i, int w) {
	auto it = st[i].lower_bound({w, -1});
	if (it == st[i].begin()) return 0;
	it--;
	return it->se;
}

void insert (int i, int w, int mx) {
	auto it = st[i].lower_bound({w, -1});

	if (it != st[i].end() && it->fi == w) {
		if (it->se >= mx) return;
		st[i].erase(it);
	}

	it = st[i].lower_bound({w, -1});
	if (it != st[i].begin()) {
		it--;
		if (it->se > mx) return;
	}
	
	st[i].emplace(w, mx);
	it = st[i].lower_bound({w, mx});
	auto jt = it;
	jt++;

	while (jt != st[i].end() && it->se > jt->se) {
		st[i].erase(jt);
		jt = it;
		jt++;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	while (m--) {
		int a, b, w;
		cin >> a >> b >> w;
		
		int ab = find(a, w) + 1;
		res = max(res, ab);
		insert(b, w, ab);
	}

	cout << res << endl;

	return 0;
}