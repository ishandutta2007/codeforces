#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 500005;
int n, a[MX], ptr[2 * MX];
vi divi[2 * MX], pos[2 * MX];
int leq_pre[MX], leq_suf[MX];
int les_pre[MX], les_suf[MX];
int geq_pre[MX], geq_suf[MX];
int gre_pre[MX], gre_suf[MX];

void find (int pre[], int suf[], auto f) {
	vi q(n);
	
	iota(all(q), 1);
	sort(all(q), f);
	
	set<int> st;
	st.insert(0), st.insert(n + 1);
	
	for (int i : q) {
		auto it = st.lower_bound(i);
		suf[i] = *it;
		
		it--;
		pre[i] = *it;
		
		st.insert(i);
	}
}

void main_() {
	forn (i, 2 * MX)
		pos[i].clear();
	
	cin >> n;
	forr (i, 1, n) {
		cin >> a[i];
		pos[a[i]].pb(i);
	}
	
	find(leq_pre, les_suf, [&] (int i, int j) {
		if (a[i] == a[j]) return i < j;
		return a[i] < a[j];
	});
	find(les_pre, leq_suf, [&] (int i, int j) {
		if (a[i] == a[j]) return i > j;
		return a[i] < a[j];
	});
	find(geq_pre, gre_suf, [&] (int i, int j) {
		if (a[i] == a[j]) return i < j;
		return a[i] > a[j];
	});
	find(gre_pre, geq_suf, [&] (int i, int j) {
		if (a[i] == a[j]) return i > j;
		return a[i] > a[j];
	});
	
	ll res = 0;
	
	forn (i, 2 * MX) ptr[i] = (int)pos[i].size() - 1;
	for (int i = n; i >= 1; i--) {
		for (int d : divi[a[i]]) {
			if (ptr[d] == -1) continue;
			int j = pos[d][ptr[d]];
			int a = max(geq_pre[i], les_pre[j]) + 1;
			int b = j;
			int c = i;
			int e = min(gre_suf[i], les_suf[j]) - 1;
			
			if (a <= b && c <= e)
				res += 1ll * (b - a + 1) * (e - c + 1);
		}
		
		ptr[a[i]]--;
	}
	
	forn (i, 2 * MX) ptr[i] = 0;
	for (int i = 1; i <= n; i++) {
		ptr[a[i]]++;
		
		for (int d : divi[a[i]]) {
			if (ptr[d] == pos[d].size()) continue;
			int j = pos[d][ptr[d]];
			int a = max(geq_pre[i], leq_pre[j]) + 1;
			int b = i;
			int c = j;
			int e = min(gre_suf[i], les_suf[j]) - 1;
			
			if (a <= b && c <= e)
				res += 1ll * (b - a + 1) * (e - c + 1);
		}
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	forr (i, 1, 2 * MX - 1)
		for (int j = i; j < 2 * MX; j += i)
			divi[j].pb(i);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}