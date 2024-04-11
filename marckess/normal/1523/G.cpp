#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
map<int, int> st[4 * MX];

bool find (map<int, int> &st, int a, int b) {
	auto it = st.lower_bound(a);
	return it != st.end() && it->se <= b;
}

int find (int i, int j, int pos, int a, int b) {
	if (i == j)
		return i;
	
	int m = (i + j) / 2;
	
	if (find(st[pos * 2], a, b))
		return find(i, m, pos * 2, a, b);
	return find(m + 1, j, pos * 2 + 1, a, b);
}

void update (int i, int j, int pos, int x, int a, int b) {
	auto it = st[pos].lower_bound(a);
	
	if (it == st[pos].end() || it->se > b) {
		while (it != st[pos].begin()) {
			auto jt = it;
			jt--;
			
			if (jt->se < b)
				break;
			
			st[pos].erase(jt);
		}
		
		st[pos][a] = b;
	}
	
	if (i == j)
		return;
	
	int m = (i + j) / 2;
	
	if (x <= m)
		return update(i, m, pos * 2, x, a, b);
	return update(m + 1, j, pos * 2 + 1, x, a, b);
}

int n, m, l[MX], r[MX], res[MX];
vi pos[MX];

int go (int a, int b) {
	if (a > b || !find(st[1], a, b))
		return 0;
	
	int i = find(1, m, 1, a, b);
	assert(a <= l[i] && r[i] <= b);
	return (r[i] - l[i] + 1)
		 + go(a, l[i] - 1)
		 + go(r[i] + 1, b);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> l[i] >> r[i];
		pos[r[i] - l[i] + 1].pb(i);
	}
	
	for (int i = n; i >= 1; i--) {
		for (int j : pos[i])
			update(1, m, 1, j, l[j], r[j]);
		res[i] = go(1, n);
	}
	
	for (int i = 1; i <= n; i++)
		cout << res[i] << endl;
	
	return 0;
}