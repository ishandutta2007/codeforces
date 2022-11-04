
// Problem : E. AmShZ and G.O.A.T.
// Contest : Codeforces - Codeforces Global Round 17
// URL : https://codeforces.com/contest/1610/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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

const int MX = 200005;
int n, a[MX], sig[MX];

void main_() {
	cin >> n;
	forn (i, n)
		cin >> a[i];
	
	a[n] = -1;
	sig[n] = n;
	
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == a[i + 1]) sig[i] = sig[i + 1];
		else sig[i] = i + 1;
	}
	
	int res = 2;
	for (int i = n - 1; i >= 0; i--) {
		if (i && a[i] == a[i - 1]) continue;
		int p = sig[i] - i, j = sig[i];
		
		while (j < n) {
			p++;
			j = lower_bound(a + j, a + n, 2 * a[j] - a[i]) - a;
		}
		
		res = max(res, p);
	}
	
	cout << n - res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}