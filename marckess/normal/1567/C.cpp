
// Problem : C. Carrying Conundrum
// Contest : Codeforces - Codeforces Round #742 (Div. 2)
// URL : https://codeforces.com/contest/1567/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

ll mem[22][2][2];
string s;
int pre[2][10][2];

ll f (int i, int a, int b) {
	if (i == s.size()) return !a && !b;
	
	ll res = mem[i][a][b];
	if (res != -1) return res;
	
	return res =
	       pre[a][s[i] - '0'][0] * f(i + 1, b, 0) +
		   pre[a][s[i] - '0'][1] * f(i + 1, b, 1);
}

void solve () {
	cin >> s;
	reverse(all(s));
	
	memset(mem, -1, sizeof(mem));
	cout << f(0, 0, 0) - 2 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	forn (a, 2)
		forn (i, 10)
			forn (j, 10) {
				int x = (a + i + j) % 10;
				int y = (a + i + j) / 10;
				pre[a][x][y]++;
			}
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}