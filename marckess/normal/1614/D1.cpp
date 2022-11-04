
// Problem : D1. Divan and Kostomuksha (easy version)
// Contest : Codeforces - Codeforces Round #757 (Div. 2)
// URL : https://codeforces.com/contest/1614/problem/D1
// Memory Limit : 1024 MB
// Time Limit : 4000 ms
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

const int MX = 5000005;
int n;
ll dp[MX], cn[MX];

void main_() {
	cin >> n;
	
	forn (i, n) {
		int a;
		cin >> a;
		
		cn[a]++;
	}
	
	for (int d = 1; d < MX; d++)
		for (int i = 2 * d; i < MX; i += d)
			cn[d] += cn[i];
		
	for (int d = 1; d < MX; d++)
		for (int i = 2 * d; i < MX; i += d)
			dp[i] = max(dp[i], dp[d] + d * (cn[d] - cn[i]));
	
	ll res = 0;
	for (int i = 1; i < MX; i++)
		res = max(res, dp[i] + i * cn[i]);
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}