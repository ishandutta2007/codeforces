#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000005;
int n, bs[MX];

void solve () {
	cin >> n;
	ll res = 1;
	
	int d = n + 1;
	while (bs[d]) d++;
	res *= d;
	
	d += n;
	while (bs[d]) d++;
	res *= d;
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for (ll i = 2; i < MX; i++)
		if (!bs[i])
			for (ll j = i * i; j < MX; j += i)
				bs[j] = 1;
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}