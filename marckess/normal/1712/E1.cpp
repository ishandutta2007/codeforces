#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
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

#include <bits/extc++.h>
using namespace __gnu_pbds;

const int MX = 200005;
int l, r, ft1[MX], ft2[MX];
vi divi[MX];

ll comb3 (ll n) {
	return n * (n - 1) * (n - 2) / 6;
}

void update (int ft[], int i, int k) {
	while (i < MX) {
		ft[i] += k;
		i += i & -i;
	}
}

int query (int ft[], int i) {
	int s = 0;
	while (i) {
		s += ft[i];
		i -= i & -i;
	}
	return s;
}

int count (int ft[], int a, int b) {
	a = max(a, 1);
	if (a > b) return 0;
	return query(ft, b) - query(ft, a - 1);
}

void main_() {
	cin >> l >> r;
	ll res = comb3(r - l + 1);
	
	for (int k = l; k <= r; k++) {
		for (int d : divi[k]) {
			if (l <= d && d < k)
				update(ft1, d, 1);
			
			if (__gcd(2 * d, k) == d)
				if (l <= 2 * d && 2 * d < k)
					update(ft2, 2 * d, 1);
		}
		
		for (int j : divi[k]) {
			if (l <= j && j < k) {
				res -= count(ft1,     k + 1 - k - j, j - 1);
				res -= count(ft2, 2 * k + 1 - k - j, j - 1);
			}
			
			if (__gcd(2 * j, k) == j)
				if (l <= 2 * j && 2 * j < k) {
					j *= 2;
					res -= count(ft1, 2 * k + 1 - k - j, j - 1);
					res -= count(ft2, 2 * k + 1 - k - j, j - 1);
				}
		}
		
		for (int d : divi[k]) {
			if (l <= d && d < k)
				update(ft1, d, -1);
			
			if (__gcd(2 * d, k) == d)
				if (l <= 2 * d && 2 * d < k)
					update(ft2, 2 * d, -1);
		}
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	for (int i = 1; i < MX; i++)
		for (int j = i; j < MX; j += i)
			divi[j].pb(i);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}