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
int n, mem[MX][2][2][2][2][2];
string s[2];

// ab
// cd
// ^
// i
int dp (int i, int j, int a, int b, int c, int d) {
	if (i == n) return 0;
	
	int &res = mem[i][j][a][b][c][d];
	if (res != -1) return res;
	res = 0;
	
	int ex0, ex1;
	
	if (j == 0) {
		assert(s[0][i] == '0' || a);
		
		ex0 = i + 1 < n && s[0][i + 1] == '1' && !b;
		ex1 = s[1][i] == '1' && !c;
	} else {
		assert(s[1][i] == '0' || c);
		
		ex0 = s[0][i] == '1' && !a;
		ex1 = i + 1 < n && s[1][i + 1] == '1' && !d;
	}
	
	if (!ex0 && !ex1) {
		res = max(res, dp(i + 1, j, b, 0, d, 0));
	}
	
	if (ex0) {
		res = max(
			res,
			dp(i, j, a || (j == 1), b || (j == 0), c, d)
		);
	}
	
	if (ex1) {
		res = max(
			res,
			dp(i, j, a, b, c || (j == 0), d || (j == 1))
		);
	}
	
	if (ex0 && !ex1) {
		if (j == 0) {
			res = max(
				res,
				dp(i + 1, 0, 1, 0, d, 0) + 1
			);
		} else {
			res = max(
				res,
				dp(i, 0, 1, b, c, d) + 1
			);
		}
	}
	
	if (!ex0 && ex1) {
		if (j == 0) {
			res = max(
				res,
				dp(i, 1, a, b, 1, d) + 1			
			);
		} else {
			res = max(
				res,
				dp(i + 1, 1, b, 0, 1, 0) + 1
			);
		}
	}
	
	return res;
}

void main_() {
	cin >> n >> s[0] >> s[1];
	
	memset(mem, -1, sizeof(mem));
	cout << dp(0, 0, 0, 0, 0, 0) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}