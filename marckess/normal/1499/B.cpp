#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 105;
int n, mem[MX][2][2];
string s;

int dp (int i, int f, int g) {
	if (i == n) return 1;
	
	int &res = mem[i][f][g];
	if (res != -1) return res;
	res = 0;
	
	if (!f) res |= dp(i + 1, 1, g);
	if (!(g && s[i] == '0')) res |= dp(i + 1, 0, g || s[i] == '1');
	
	return res;
}

void solve () {
	cin >> s;
	n = s.size();
	
	memset(mem, -1, sizeof(mem));
	if (dp(0, 0, 0)) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}