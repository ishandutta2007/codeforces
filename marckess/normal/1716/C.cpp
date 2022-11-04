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

const int MX = 200005;
int n, a[2][MX];
map<int, ii> izq, der;

void up (int i, int j, int off, int &mx, ii &pos) {
	if (a[i][j] - off > mx) {
		mx = a[i][j] - off;
		pos = {i, j};
	}
}

int to (ii p, int i, int f, int ini) {
	int off;
	
	if (p.fi == f) {
		off = a[p.fi][p.se] + 2 * (n - i) - (p.se - i);
	} else {
		off = a[p.fi][p.se] + (p.se - i) + 1;
	}
	
	return max(ini + 2 * (n - i), off);
}

void main_() {
	cin >> n;
	forn (i, 2)
	forn (j, n) {
		cin >> a[i][j];
		if (a[i][j] == 0)
			a[i][j] = -1;
	}
	
	izq.clear();
	der.clear();
	
	int x = 0, y = 1, mizq = -2e9, mder = -2e9;
	ii aizq, ader;
	for (int i = n - 1; i >= 0; i--, x--, y++) {
		up(0, i, x, mizq, aizq);
		up(1, i, y, mizq, aizq);
		izq[i] = aizq;
		
		up(0, i, y, mder, ader);
		up(1, i, x, mder, ader);
		der[i] = ader;
	}
	
	int res = to(aizq, 0, 0, -1);
	
	int t = -1;
	forn (j, n) {
		if (a[j % 2][j] > t)
			t = a[j % 2][j] + 1;
		else
			t++;
			
		if (a[1 - j % 2][j] > t)
			t = a[1 - j % 2][j] + 1;
		else
			t++;
		
		int p = t;
		
		if (j + 1 < n) {
			if (j % 2 == 0) {
				p = to(der[j + 1], j + 1, 1, t);
			} else {
				p = to(izq[j + 1], j + 1, 0, t);
			}
		}
		
		res = min(res, p);
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