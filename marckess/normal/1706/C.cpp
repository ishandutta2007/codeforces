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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, a[MX], vis[MX];
ii mem[MX];

ii operator + (ii a, ii b) {
	return {a.fi + b.fi, a.se + b.se};
}

ii dp (int i) {
	if (i + 1 >= n) return {0, 0};
	
	auto &res = mem[i];
	if (vis[i]) return res;
	vis[i] = 1;
	
	ii x = dp(i + 1);
	ii y = dp(i + 2) + ii(1, -max(0, max(a[i - 1], a[i + 1]) - a[i] + 1));
	
	return res = max(x, y);
}

void main_() {
	cin >> n;
	forn (i, n) {
		cin >> a[i];
		vis[i] = 0;
	}
	cout << -dp(1).se << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}