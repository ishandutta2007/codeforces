#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

ll gcd (ll a, ll b) {return b ? gcd(b, a%b) : a;}
ll a, b, x, y;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> a >> b >> x >> y;
	ll d = gcd(x, y);
	cout << min(a/(x/d), b/(y/d)) << endl;

	return 0;
}