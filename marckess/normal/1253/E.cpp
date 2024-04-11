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
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
int n, m, x[MX], s[MX], mem[MX];

int dp (int i) {
	if (i > m)
		return 0;

	int &res = mem[i];
	if (res != -1)
		return res;
	res = m - i + 1;

	for (int j = 0; j < n; j++) {
		if (x[j] - s[j] <= i && i <= x[j] + s[j])
			res = min(res, dp(x[j] + s[j] + 1));
		else if (i < x[j]) {
			int d = x[j] - s[j] - i;
			res = min(res, dp(x[j] + s[j] + d + 1) + d);
		}
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> s[i];

	memset(mem, -1, sizeof(mem));
	cout << dp(1) << endl;

	return 0;
}