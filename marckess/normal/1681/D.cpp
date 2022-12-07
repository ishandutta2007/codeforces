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

int n;
ll x;
map<ll, int> mem;

int dp (ll x) {
	if (mem.count(x))
		return mem[x];
		
	int &res = mem[x];
	res = 1e9;
	
	string s = to_string(x);
	if (s.size() == n)
		return res = 0;
	
	int mk = 0;
	for (char c : s)
		mk |= 1 << (c - '0');
	
	forr (j, 2, 9)
		if (mk & (1 << j))
			res = min(res, dp(j * x) + 1);
	
	return res;
}

void main_() {
	cin >> n >> x;
	
	int res = dp(x);
	if (res != 1e9) cout << res << endl;
	else cout << -1 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}