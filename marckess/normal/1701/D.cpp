// Powered by CP Editor (https://cpeditor.org)

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
int n, p[MX], b[MX], l[MX], r[MX];
vi pos[MX];
set<ii> st;

void main_() {
	cin >> n;
	
	forr (i, 1, n)
		pos[i].clear();
	
	forr (i, 1, n) {
		cin >> b[i];
		l[i] = i / (b[i] + 1) + 1;
		r[i] = b[i] ? i / b[i] : n;
		pos[r[i]].pb(i);
	}
	
	for (int i = n; i >= 1; i--) {
		for (int j : pos[i])
			st.emplace(l[j], j);
		
		auto it = *st.rbegin();
		p[it.se] = i;
		st.erase(it);
	}
	
	forr (i, 1, n)
		cout << p[i] << " ";
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