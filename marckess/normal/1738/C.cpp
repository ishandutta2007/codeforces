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

const int MX = 105;
int n, a[MX], mem[MX][MX][2][2];

int dp (int i, int j, int f, int g) {
	if (!i && !j) return g == 0;
	
	int &res = mem[i][j][f][g];
	if (res != -1) return res;
	
	if (f) {
		if (i && !dp(i - 1, j, 0, g))
			return res = 0;
		
		if (j && !dp(i, j - 1, 0, g))
			return res = 0;
		
		return res = 1;
	}
	
	if (i && dp(i - 1, j, 1, g))
		return res = 1;
	
	if (j && dp(i, j - 1, 1, g ^ 1))
		return res = 1;
	
	return res = 0;
}

void main_() {
	cin >> n;
	
	int p = 0;
	
	forn (i, n) {
		cin >> a[i];
		
		if (a[i] % 2 == 0)
			p++;
	}
	
	if (dp(p, n - p, 0, 0)) cout << "Alice" << endl;
	else cout << "Bob" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(mem, -1, sizeof(mem));
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}