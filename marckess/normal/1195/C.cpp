#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
int n, h[2][MX];
ll mem[2][MX];

ll dp (int i, int j) {
	if (j == n) return 0;
	ll &res = mem[i][j];
	if (res != -1) return res;
	return res = max(dp(i, j + 1), dp(1 - i, j + 1) + h[i][j]);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	forn(i, 2) forn(j, n) cin >> h[i][j];
	memset(mem, -1, sizeof(mem));
	cout << max(dp(0, 0), dp(1, 0)) << endl;  
 
	return 0;
}