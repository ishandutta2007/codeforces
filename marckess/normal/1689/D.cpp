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

const int MX = 1005;
int n, m;
char c[MX][MX];
int to[4];
int mx[] = {1, 1, -1, -1};
int my[] = {1, -1, 1, -1};

void main_() {
	cin >> n >> m;
	forn (i, n)
		cin >> c[i];

	forn (i, 4)
		to[i] = -1e9;
	
	forn (i, n)
	forn (j, m)
		if (c[i][j] == 'B')
			forn (l, 4)
				to[l] = max(to[l], i * mx[l] + j * my[l]);
	
	int ri, rj, res = 1e9;
	forn (i, n)
	forn (j, m) {
		int p = -1e9;
		forn (l, 4)
			p = max(p, to[l] - (i * mx[l] + j * my[l]));
		
		if (p < res) {
			res = p;
			ri = i;
			rj = j;
		}
	}
	
	cout << ri + 1 << " " << rj + 1 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}