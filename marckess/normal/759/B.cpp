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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
int n, t[MX];
ll mem[MX];

ll dp (int i) {
	if (i == 0) return 0;

	ll &res = mem[i];
	if (res != -1) return res;
	res = dp(i - 1) + 20;

	for (int j = i; j >= 0; j--)
		if (t[i] > t[j] + 90 - 1) {
			res = min(res, dp(j) + 50);
			break;
		}

	for (int j = i; j >= 0; j--)
		if (t[i] > t[j] + 1440 - 1) {
			res =  min(res, dp(j) + 120);
			break;
		}

	return res;
}


int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(mem, -1, sizeof(mem));

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> t[i];
	t[0] = -1e9;

	for (int i = 1; i <= n; i++)
		cout << dp(i) - dp(i - 1) << endl;

	return 0;
}