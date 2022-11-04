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
typedef vector<ll> vi;
typedef vector<ii> vii;

const int MX = 505;
int n, a[MX], mem[MX][MX], mem1[MX];

int dp (int i, int j) {
	if (i == j) return a[i];
	int &res = mem[i][j];
	if (res != -1) return res;
	res = 0;

	for (int k = i; k < j; k++) {
		int a = dp(i, k);
		int b = dp(k + 1, j);
		if (a && a == b) res = a + 1;
	}

	return res;
}

int dp1 (int i) {
	if (i == n) return 0;
	int &res = mem1[i];
	if (res != -1) return res;
	res = 1 + dp1(i + 1);

	for (int j = i + 1; j < n; j++)
		if (dp(i, j))
			res = min(res, 1 + dp1(j + 1));

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	memset(mem, -1, sizeof(mem));
	memset(mem1, -1, sizeof(mem1));
	cout << dp1(0) << endl;

	return 0;
}