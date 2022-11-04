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

const int MX = 2005;
int n, k, r[MX][MX];
vector<tuple<int, int, int>> a;
vii res;

void main_() {
	cin >> n >> k;
	
	forn (i, n)
	forn (j, n) {
		int x;
		cin >> x;
		a.pb({x, i, j});
	}
	
	sort(all(a), greater<tuple<int, int, int>>());
	
	vi mx(4, -1e9);
	for (auto &[x, i, j] : a) {
		int d = 0;
		
		forn (l, 4) {
			int p = mx[l];
			
			if (l & 1) p += i;
			else p -= i;
			
			if (l & 2) p += j;
			else p -= j;
			
			d = max(d, p);
		}
		
		if (d <= k) {
			r[i][j] = 1;
			
			forn (l, 4) {
				int p = 0;
				
				if (l & 1) p -= i;
				else p += i;
				
				if (l & 2) p -= j;
				else p += j;
				
				mx[l] = max(mx[l], p); 
			}
		}
	}
	
	forn (i, n) {
		forn (j, n)
			cout << "GM"[r[i][j]];
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}