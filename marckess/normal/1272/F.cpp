#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 205;
int mem[MX][MX][2*MX];
string s, t;

int dp (int i, int j, int k) {
	if (i == s.size() && j == t.size() && k == 0)
		return 0;
	
	if (k < 0) return 1e9;
	if (k == 2 * MX) return 1e9;
	
	int &res = mem[i][j][k];
	if (res != -1)
		return res;
	res = 1e9;

	int a = 0, b = 0;
	if (i < s.size() && s[i] == '(') a = 1;
	if (j < t.size() && t[j] == '(') b = 1;
	res = min(res, dp(i + a, j + b, k + 1) + 1);

	a = 0, b = 0;
	if (i < s.size() && s[i] == ')') a = 1;
	if (j < t.size() && t[j] == ')') b = 1;
	res = min(res, dp(i + a, j + b, k - 1) + 1);

	return res;
}

void rec (int i, int j, int k) {
	if (i == s.size() && j == t.size() && k == 0)
		return;

	int a = 0, b = 0, c = 0, d = 0, x, y;
	if (i < s.size() && s[i] == '(') a = 1;
	if (j < t.size() && t[j] == '(') b = 1;
	x = dp(i + a, j + b, k + 1);


	if (i < s.size() && s[i] == ')') c = 1;
	if (j < t.size() && t[j] == ')') d = 1;
	y = dp(i + c, j + d, k - 1);

	if (x < y) {
		cout << '(';
		rec(i + a, j + b, k + 1);
	} else {
		cout << ')';
		rec(i + c, j + d, k - 1);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(mem, -1, sizeof(mem));

	cin >> s >> t;
	rec(0, 0, 0);
	cout << endl;

	return 0;
}