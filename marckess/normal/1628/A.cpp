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

const int MX = 222222;
int n, a[MX];
vi pos[MX];

void main_() {
	cin >> n;
	
	forn (i, n + 5)
		pos[i].clear();
	
	forn (i, n) {
		cin >> a[i];
		pos[a[i]].pb(i);
	}
	
	vi res;
	int last = 0;
	
	while (last < n) {
		int x = 0;
		int to = last;
		
		while (1) {
			auto it = lower_bound(all(pos[x]), last);
			if (it == pos[x].end()) break;
			
			x++;
			to = max(to, *it);
		}
		
		res.pb(x);
		last = to + 1;
	}
	
	cout << res.size() << endl;
	for (int x : res)
		cout << x << " ";
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