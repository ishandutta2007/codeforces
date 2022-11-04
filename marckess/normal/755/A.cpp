#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 1000005;
int n;
bitset<MX> bs;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i < MX; i++)
		if (bs[i])
			for (ll j = i * i; j < MX; j += i)
				bs[j] = 0;

	cin >> n;
	int m = 1;
	while (1) {
		if (!bs[n * m + 1]) {
			cout << m << endl;
			return 0;
		}
		m++;
	}

	return 0;
}