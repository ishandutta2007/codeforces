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

const int MX = 100005;
int n, k, a[MX], ex[MX], ant[MX];

void main_() {
	cin >> n >> k;
	
	memset(ex, 0, sizeof(ex));
	memset(ant, -1, sizeof(ant));
	int mn = MX;
	
	forn (i, n) {
		cin >> a[i];
		ex[a[i]] = 1;
		mn = min(mn, a[i]);
	}
	
	forr (i, 1, MX - 1) {
		if (ex[i])
			ant[i] = i;
		else
			ant[i] = ant[i - 1];
	}
	
	int res = MX;
	
	forr (i, 1, mn) {
		int mx = i;
		for (int ini = i, fin = 2 * i - 1, p = 1; ini < MX; ini += i, fin += i, p++) {
			if (fin >= MX) fin = MX - 1;
			if (p > k) p = k;
			
			int x = ant[fin];
			if (x >= ini) {
				mx = max(mx, x / p);
			}
		}
		res = min(res, mx - i);
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