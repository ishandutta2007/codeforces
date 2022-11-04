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
typedef double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int x, k, p;
ld mem[205][1 << 8][2][230];
char vis[205][1 << 8][2][230];

ld dp (int i, int x, int f, int j) {
	if (i == k) {
		if (x)
			forn (l, 8)
				if (x & (1 << l))
					return l;
		if (f) return 8;
		return 8 + j;
	}
	
	ld &res = mem[i][x][f][j];
	if (vis[i][x][f][j]) return res;
	vis[i][x][f][j] = 1;
	
	if (x + 1 == (1 << 8)) {
		if (f)
			res += (1 - p / ld(100)) * dp(i + 1, 0, 0, j);
		else
			res += (1 - p / ld(100)) * dp(i + 1, 0, 1, 1);
	} else {
		res += (1 - p / ld(100)) * dp(i + 1, x + 1, f, j);
	}
	
	if (x & (1 << 7)) {
		if (f)
			res += p / ld(100) * dp(i + 1, (x << 1) & ((1 << 8) - 1), 1, j + 1);
		else
			res += p / ld(100) * dp(i + 1, (x << 1) & ((1 << 8) - 1), 1, 1);
	} else {
		if (f)
			res += p / ld(100) * dp(i + 1, x << 1, 0, 1);
		else
			res += p / ld(100) * dp(i + 1, x << 1, 0, j + 1);
	}
	
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);
	
	cin >> x >> k >> p;
	
	int suf = 0;
	for (int i = 8; bool(x & (1 << i)) == bool(x & (1 << 8)) && i < 30; i++, suf++);
	
	cout << dp(0, x & ((1 << 8) - 1), (x >> 8) & 1, suf) << endl;
	
	return 0;
}