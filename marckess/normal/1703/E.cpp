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

const int MX = 105;
int n;
char c[MX][MX];

void main_() {
	cin >> n;
	forn (i, n)
		cin >> c[i];
	
	int res = 0;
	set<vii> vis;
	
	forn (i, n)
	forn (j, n) {
		set<ii> st;
		
		st.emplace(i, j);
		st.emplace(j, n - i - 1);
		st.emplace(n - i - 1, n - j - 1);
		st.emplace(n - j - 1, i);
		
		vii v;
		
		int cn = 0;
		for (ii x : st) {
			if (c[x.fi][x.se] == '1')
				cn++;
			v.pb(x);
		}
		
		if (!vis.count(v))
			res += min(cn, (int)st.size() - cn);
		vis.insert(v);
	}
	
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