#include <bits/stdc++.h>

//#define endl '\n'
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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 400005;
ii a[MX];
set<int> st;
int n, in[MX], si[MX], izq[MX], res;

void no () {
	cout << -1 << endl;
	exit(0);
}

void check (int v) {
	if (si[v] == 3) no();
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n) {
		cin >> a[i].fi >> a[i].se;
		
		st.insert(a[i].fi);
		st.insert(a[i].se);
		
		in[a[i].fi] = i;
		in[a[i].se] = i;
	}
	
	while (st.size()) {
		int p = 0;
		set<int> ex;
		
		queue<int> q;
		q.push(*st.begin());
		si[*st.begin()] = 1;
		izq[*st.begin()] = 1;
		
		st.erase(*st.begin());
		
		while (q.size()) {
			int u = q.front();
			q.pop();
			
			check(u);
			
			int pos = in[u], fi = (u == a[pos].fi), ot;
			ex.insert(pos);
			
			if (fi == 1 && si[u] != 1) p++;
			if (fi == 0 && si[u] != 2) p++;
			
			if (fi) ot = a[pos].se, si[ot] |= 3 ^ si[u];
			else ot = a[pos].fi, si[ot] |= 3 ^ si[u];
			
			st.erase(ot);
			
			if (izq[u] == 1) {
				while (st.size() && *st.rbegin() > ot) {
					int x = *st.rbegin();
					st.erase(x);
					
					izq[x] = -1;
					si[x] |= si[u];
					q.push(x);
				}
			} else {
				while (st.size() && *st.begin() < ot) {
					int x = *st.begin();
					st.erase(x);
					
					izq[x] = 1;
					si[x] |= si[u];
					q.push(x);
				}
			}
		}
		
		int sz = ex.size();
		res += min(p, sz - p);
	}
	
	for (int i = 1; i <= 2 * n; i++)
		check(i);
	
	cout << res << endl;

	return 0;
}