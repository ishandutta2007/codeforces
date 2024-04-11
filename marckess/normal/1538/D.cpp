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

const int MX = 32000;
int a, b, k, bs[MX];
vi pr;

int f (int n) {
	int res = 0;
	
	for (int x : pr) {
		if (x * x > n)
			break;
			
		while (n % x == 0) {
			n /= x;
			res++;
		}
	}
	
	if (n > 1)
		res++;
		
	return res;
}

void solve () {
	cin >> a >> b >> k;
	
	if (k == 1) {
		if (a == b) cout << "NO" << endl;
		else if (a % b == 0 || b % a == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
		return;
	}
	
	if (f(a) + f(b) >= k) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	for (ll i = 2; i < MX; i++)
		if (!bs[i]) {
			pr.pb(i);
			for (ll j = i * i; j < MX; j += i)
				bs[j] = 1;
		}
 	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}