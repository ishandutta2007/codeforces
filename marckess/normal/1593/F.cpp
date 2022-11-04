
// Problem : F. Red-Black Number
// Contest : Codeforces - Codeforces Round #748 (Div. 3)
// URL : https://codeforces.com/contest/1593/problem/F
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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

const int MX = 41;
int n, a, b, ba[MX], bb[MX], mem[MX][MX][MX][MX];
string s;

int dp (int i, int ra, int rb, int j, int k) {
	if (j < 0 || k < 0) return 0;
	if (i == n) return ra == 0 && rb == 0 && j == 0 && k == 0;
	
	int &res = mem[i][ra][rb][k];
	if (res != -1) return res;
	
	return res =
		dp(i + 1, (ra + (s[i] - '0') * ba[j - 1]) % a, rb, j - 1, k) ||
		dp(i + 1, ra, (rb + (s[i] - '0') * bb[k - 1]) % b, j, k - 1);
}

void rec (int i, int ra, int rb, int j, int k) {
	if (i == n) return;
	
	if (dp(i + 1, (ra + (s[i] - '0') * ba[j - 1]) % a, rb, j - 1, k)) {
		cout << 'R';
		return rec(i + 1, (ra + (s[i] - '0') * ba[j - 1]) % a, rb, j - 1, k);
	}
	
	cout << 'B';
	return rec(i + 1, ra, (rb + (s[i] - '0') * bb[k - 1]) % b, j, k - 1);
}

void main_() {
	cin >> n >> a >> b >> s;
	
	ba[0] = bb[0] = 1;
	for (int i = 1; i < MX; i++) {
		ba[i] = (ba[i - 1] * 10) % a;
		bb[i] = (bb[i - 1] * 10) % b;
	}
	
	int mn = 1e9, r;
	memset(mem, -1, sizeof(mem));
	for (int i = 1; i < n; i++)
		if (dp(0, 0, 0, i, n - i))
			if (abs(i - (n - i)) < mn) {
				mn = abs(i - (n - i));
				r = i;
			}
	
	if (mn == 1e9) cout << -1;
	else rec(0, 0, 0, r, n - r);
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