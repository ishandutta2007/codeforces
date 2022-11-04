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

const int MK = 505, MC = 105;
int n, mem[55][2 * MK][2 * MC];
string s;

int dp (int i, int k, int c) {
	if (i == n) return (c != MC) * 1e9;
	if (k < 0 || 2 * MK <= k) return 1e9;
	if (c < 0 || 2 * MC <= c) return 1e9;
	
	int &res = mem[i][k][c];
	if (res != -1) return res;
	res = 1e9;
	int x = k - MK;
	int y = (c - MC) * 10;
	
	for (int j = 0; j <= 10; j++) {
		res = min(
			res, 
			dp(i + 1, x + j + MK, (y + int(s[i] - '0') - (x + j)) + MC)
			+ j * (n - i)
		);
		
		res = min(
			res,
			dp(i + 1, x - j + MK, (y + int(s[i] - '0') - (x - j)) + MC)
			+ j * (n - i)
		);
	}
	
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(mem, -1, sizeof(mem));
	
	cin >> s;
	s = "0" + s;
	n = s.size();
	cout << dp(0, MK, MC) << endl;
		
	return 0;
}