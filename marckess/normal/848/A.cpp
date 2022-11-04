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
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
int k;
ll dp[MX];
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> k;
	if (!k) {
		cout << "a" << endl;
		return 0;
	}

	dp[1] = 0;
	for (int i = 2; i < MX; i++) {
		ll a = i / 2, b = i - a;
		dp[i] = a * b + dp[a] + dp[b];
	}

	for (int i = 'a'; i <= 'z' && k; i++) {
		int x = 1;
		while (dp[x + 1] <= k)
			x++;
		k -= dp[x];
		while (x--)
			s.pb(i);
	}

	cout << s << endl;

	return 0;
}