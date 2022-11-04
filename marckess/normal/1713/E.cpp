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

const int MX = 1005;
int n, a[MX][MX], p[2 * MX];

int neg (int a) {
	if (a < n) return a + n;
	return a - n;
}

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

void join (int a, int b) {
	p[parent(a)] = parent(b);
}

bool isPos (int a, int b, int c, int d) {
	a = parent(a);
	b = parent(b);
	c = parent(c);
	d = parent(d);
	
	if (b == c) return 0;
	if (a == d) return 0;
	
	join(a, b);
	join(c, d);
	
	return 1;
}

void main_() {
	cin >> n;
	forn (i, n)
	forn (j, n)
		cin >> a[i][j];
	
	iota(p, p + 2 * n, 0);
	
	forn (i, n)
	forn (j, n) {
		if (i >= j) continue;
		if (a[i][j] == a[j][i]) continue;
		
		if (a[i][j] < a[j][i]) {
			if (isPos(i, j, neg(i), neg(j))) {
				
			} else {
				swap(a[i][j], a[j][i]);
			}
		} else {
			if (isPos(i, neg(j), neg(i), j)) {
				swap(a[i][j], a[j][i]);
			} else {
				
			}
		}
	}
	
	forn (i, n) {
		forn (j, n)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}