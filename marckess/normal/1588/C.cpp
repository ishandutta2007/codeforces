
// Problem : C. Game with Stones
// Contest : Codeforces - Codeforces Round #755 (Div. 1, based on Technocup 2022 Elimination Round 2)
// URL : https://codeforces.com/contest/1588/problem/C
// Memory Limit : 256 MB
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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;
int n, a[MX];

void main_() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	map<ll, int> mp[2];
	map<ll, vi> pos;
	vector<ll> x = {0, 0};
	
	mp[1][0] = 0;
	pos[0].pb(0);
	
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		x[i % 2] += a[i];
		x[1 - i % 2] -= a[i];
		
		int to = -1;
		
		auto it = mp[i % 2].upper_bound(x[i % 2]);
		if (it != mp[i % 2].end())
			to = max(to, it->se);
		
		it = mp[1 - i % 2].upper_bound(x[1 - i % 2]);
		if (it != mp[1 - i % 2].end())
			to = max(to, it->se);
		
		while (mp[1 - i % 2].size() && mp[1 - i % 2].begin()->fi <= x[1 - i % 2])
			mp[1 - i % 2].erase(mp[1 - i % 2].begin());
		mp[1 - i % 2][x[1 - i % 2]] = i;
		
		{
			auto it = upper_bound(all(pos[x[0]]), to);
			res += pos[x[0]].end() - it;
			pos[x[0]].pb(i);
		}
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}