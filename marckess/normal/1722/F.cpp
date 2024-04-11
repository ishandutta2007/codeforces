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

const int MX = 55;
int n, m, vis[MX][MX];
string s[MX];

int mx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int my[] = {0, 1, 0, -1, 1, -1, 1, -1};

bool valid (int x, int y) {
	if (0 <= x && x < n)
	if (0 <= y && y < m)
	if (s[x][y] == '*')
		return 1;
	return 0;
}

int cn;
void dfs (int i, int j) {
	cn++;
	vis[i][j] = 1;
	
	forn (l, 8) {
		int x = i + mx[l];
		int y = j + my[l];
		
		if (valid(x, y))
		if (!vis[x][y])
			dfs(x, y);
	}
}

void main_() {
	cin >> n >> m;
	forn (i, n) cin >> s[i];
	
	memset(vis, 0, sizeof(vis));
	
	int tot = 0;
	forn (i, n)
	forn (j, m)
		if (s[i][j] == '*' && !vis[i][j]) {
			cn = 0;
			dfs(i, j);
			if (cn != 3) {
				cout << "NO" << endl;
				return;
			}
			tot += cn;
		}
	
	int found = 0;
	forn (i, n)
	forn (j, m)
	if (s[i][j] == '*') {
		forn (l, 4) {
			int cn = 1;
			cn += valid(i + mx[l], j + my[l]);
			cn += valid(i + mx[(l + 1) % 4], j + my[(l + 1) % 4]);
			
			found += 3 * (cn == 3);
		}
	}
	
	if (found == tot) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}