// Powered by CP Editor (https://cpeditor.org)

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

const int MX = 200005;
int n, a[MX], mem[MX][2][2][2];

int dp (int i, int f, int g, int h) {
	if (f > 1) return 1e9;
	if (i == n) {
		if (g) return 1e9;
		return 0;
	}
	
	int &res = mem[i][f][g][h];
	if (res != -1) return res;
	res = 1e9;
	
	res = min(res, dp(i + 1, f, 1, 0) + 1);
	
	if (g) {
		res = min(res, dp(i + 1, f + 1, 0, 0));
	} else {
		res = min(res, dp(i + 1, f + (h && a[i] == a[i - 1]), 0, 1));
	}
	
	return res;
}

void main_() {
	cin >> n;
	
	forn (i, n) {
		cin >> a[i];
		memset(mem[i], -1, sizeof(mem[i]));
	}
	
	cout << dp(0, 0, 0, 0) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}