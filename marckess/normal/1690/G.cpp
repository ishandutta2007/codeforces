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
int n, m, a[MX];
set<ii> st;

set<ii>::iterator find (int x) {
	auto it = st.upper_bound(ii(x, MX));
	it--;
	return it;
}

void main_() {
	cin >> n >> m;
	forr (i, 1, n)
		cin >> a[i];
	
	st.clear();
	st.emplace(1, 1);
	
	forr (i, 2, n) {
		if (a[i] < a[st.rbegin()->fi])
			st.emplace(i, i);
		else {
			auto p = *st.rbegin();
			st.erase(p);
			p.se++;
			st.insert(p);
		}
	}
	
	while (m--) {
		int i, x;
		cin >> i >> x;
		
		auto it = find(i);
		int act = a[it->fi];
		
		a[i] -= x;
		
		if (a[i] < act) {
			auto p = *it;
			auto jt = it; jt++;
			
			st.erase(it);
			if (p.fi < i) {
				st.emplace(p.fi, i - 1);
				p.fi = i;
			}
			
			while (jt != st.end()) {
				it = jt;
				jt++;
				
				if (a[i] <= a[it->fi]) {
					p.se = it->se;
					st.erase(it);
				} else {
					break;
				}
			}
			
			st.insert(p);
		}
		
		cout << st.size() << " ";
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}