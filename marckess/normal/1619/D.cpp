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
int n, m, cn[MX], ex[MX], a, b;

void main_() {
	cin >> m >> n;
	forn (i, n) ex[i] = 0;
	forn (j, m) cn[j] = 0;
	a = b = 0;
	
	vvi p;
	forn (j, m)
		forn (i, n) {
			int x;
			cin >> x;
			p.pb({x, i, j});
		}
	
	sort(all(p), greater<vi>());
	forn (k, n * m) {
		int i = p[k][1];
		int j = p[k][2];
		
		if (!ex[i])
			a++;
		ex[i] = 1;
		
		cn[j]++;
		if (cn[j] > 1)
			b = 1;
		
		if (a == n && b) {
			cout << p[k][0] << endl;
			return;
		}
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