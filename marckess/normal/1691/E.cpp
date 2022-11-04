// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
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

const int MX = 100005;
int n, p[MX], x[MX], y[MX];
vvi v;
set<ii> a, b;

int parent (int a) {
	return p[a] == a ? a : p[a] = parent(p[a]);
}

void del (int i) {
	a.erase({x[i], i});
	b.erase({y[i], i});
}

void join (int a, int b) {
	a = parent(a), b = parent(b);
	
	if (a == b) return;
	
	del(a);
	del(b);
	
	x[a] = max(x[a], x[b]);
	y[a] = max(y[a], y[b]);
	p[b] = a;
}

void main_() {
	a.clear();
	b.clear();
	v.clear();
	
	cin >> n;
	
	v.clear();
	forn (i, n) {
		int c, l, r;
		cin >> c >> l >> r;
		v.pb({c, l, r});
	}
	
	sort(all(v), [&] (vi &a, vi &b) {
		return a[2] < b[2];
	});
	
	forn (i, n) {
		int c = v[i][0];
		int l = v[i][1];
		int r = v[i][2];
		
		p[i] = i;
		x[i] = c == 0 ? r : -1;
		y[i] = c == 1 ? r : -1;
		
		auto &st = c == 0 ? b : a;
		
		while (st.size() && l <= st.rbegin()->fi) {
			ii p = *st.rbegin();
			join(i, p.se);
			st.erase(p);
		}
		
		a.insert({x[parent(i)], parent(i)});
		b.insert({y[parent(i)], parent(i)});
	}
	
	int res = 0;
	forn (i, n)
		res += i == parent(i);
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}