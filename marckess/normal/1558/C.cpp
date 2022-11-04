
// Problem : C. Bottom-Tier Reversals
// Contest : Codeforces - Codeforces Round #740 (Div. 1, based on VK Cup 2021 - Final (Engine))
// URL : https://codeforces.com/contest/1558/problem/C
// Memory Limit : 512 MB
// Time Limit : 2000 ms
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

const int MX = 2222;
int n, a[MX];
vi res;

ii find (int x, int y) {
	int rx, ry;
	for (int i = 1; i <= n; i++) {
		if (a[i] == x) rx = i;
		if (a[i] == y) ry = i;
	}
	return {rx, ry};
}

void swap (int x) {
	res.pb(x);
	reverse(a + 1, a + x + 1);
}

void solve () {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
		
	int f = 1;
	for (int i = 1; i <= n; i++)
		f &= i % 2 == a[i] % 2;
	
	if (!f) {
		cout << -1 << endl;
		return;
	}
	
	res.clear();
	for (int i = n; i > 1; i -= 2) {
		auto [x, y] = find(i, i - 1);
		
		swap(x);
		tie(x, y) = find(i, i - 1);
		
		swap(y - 1);
		tie(x, y) = find(i, i - 1);
		
		swap(y + 1);
		tie(x, y) = find(i, i - 1);
		
		swap(x);
		tie(x, y) = find(i, i - 1);
		
		swap(i);
	}
	
	cout << res.size() << endl;
	for (int x : res)
		cout << x << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}