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
int n, a[MX];
string s;
ll mem[MX][2];

ll dp (int i, int f) {
	if (i == -1) return 0;
	
	ll &res = mem[i][f];
	if (res != -1) return res;
	res = 0;
	
	if (s[i] == '1' || f)
		res = max(res, dp(i - 1, 0) + a[i]);
	else
		res = max(res, dp(i - 1, 0));
	
	if (f)
		res = max(res, dp(i - 1, s[i] == '1') + a[i]);
	else
		res = max(res, dp(i - 1, s[i] == '1'));
	
	return res;
}

void main_() {
	cin >> n >> s;
	forn (i, n) {
		cin >> a[i];
		memset(mem[i], -1, sizeof(mem[i]));
	}
	cout << dp(n - 1, 0) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}