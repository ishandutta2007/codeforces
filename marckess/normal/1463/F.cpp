#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, x, y;
int dp[2][1 << 22];

void maxi (int &a, int b) {
	if (a < b)
		a = b;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> x >> y;
	if (x > y)
		swap(x, y);
		
	int mk = (1 << y) - 1, f = 0, g = 1, m = x + y;
	
	forn (i, (1 << y))
		dp[0][i] = -1e9;
	dp[0][0] = 0;
	
	forn (_, m) {
		forn (i, (1 << y))
			dp[g][i] = -1e9;
		
		forn (i, (1 << y)) {
			int to = i << 1;
			
			maxi(dp[g][to & mk], dp[f][i]);
			
			if ((~to & (1 << x)) && (~to & (1 << y)))
				maxi(dp[g][(to & mk) + 1], dp[f][i] + 1);
		}
		
		swap(f, g);
	}
	
	forn (i, (1 << y))
		if (dp[f][i] > 0)
			dp[f][i] *= n / m;
	
	forn (_, n % m) {
		forn (i, (1 << y))
			dp[g][i] = -1e9;
		
		forn (i, (1 << y)) {
			int to = i << 1;
			
			maxi(dp[g][to & mk], dp[f][i]);
			
			if ((~to & (1 << x)) && (~to & (1 << y)))
				maxi(dp[g][(to & mk) + 1], dp[f][i] + 1);
		}
		
		swap(f, g);
	}
		
	cout << *max_element(dp[f], &dp[f][1 << y]) << endl;
	
	return 0;
}