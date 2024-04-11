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

int dp[(1<<20)+5], n, res;
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s;
	n = s.size();

	for (int i = 0; i < n; i++) {
		int mk = 0;
		for (int j = i; j < n; j++) {
			if (mk & (1 << s[j] - 'a'))
				break;
			mk |= 1 << s[j] - 'a';
			dp[mk] = j - i + 1;
			res = max(res, j - i + 1);
		}
	}

	for (int j = 0; j < 20; j++)
		for (int i = 0; i < (1 << 20); i++)
			if (~i & (1 << j))
				dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i]);

	for (int i = 0; i < n; i++) {
		int mk = 0;
		for (int j = i; j < n; j++) {
			if (mk & (1 << s[j] - 'a'))
				break;
			mk |= 1 << s[j] - 'a';
			
			int aux = mk;
			aux ^= (1 << 20) - 1;
			res = max(res, j - i + 1 + dp[aux]);
		}
	}

	cout << res << endl;

	return 0;
}