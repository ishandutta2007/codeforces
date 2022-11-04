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
int n, c[MX], mem[MX][2];
vi pos[MX];

int dp (vi &pos, int i, int f) {
	if (i == pos.size()) return 0;
	
	int &res = mem[i][f];
	if (res != -1) return res;
	res = dp(pos, i + 1, f);
	
	if (pos[i] % 2 == f)
		res = max(res, dp(pos, i + 1, 1 - f) + 1);
		
	return res;
}

void main_() {
	cin >> n;
	forr (i, 1, n) {
		pos[i].clear();
	}
	forn (i, n) {
		cin >> c[i];
		pos[c[i]].pb(i);
	}
	forr (i, 1, n) {
		forn (j, pos[i].size() + 2)
			memset(mem[j], -1, sizeof(mem[j]));
		cout << max(dp(pos[i], 0, 0), dp(pos[i], 0, 1)) << " ";
	}
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