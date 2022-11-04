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
ll ft1[MX], ft2[MX], acu[MX];
vi divi[MX];

ll comb3 (ll n) {
	return n * (n - 1) * (n - 2) / 6;
}

void update (ll ft[], int i, ll k) {
	while (i < MX) {
		ft[i] += k;
		i += i & -i;
	}
}

ll query (ll ft[], int i) {
	ll s = 0;
	while (i) {
		s += ft[i];
		i -= i & -i;
	}
	return s;
}

ll count (ll ft[], int a, int b) {
	a = max(a, 1);
	if (a > b) return 0;
	return query(ft, b) - query(ft, a - 1);
}

int n, l[MX], r[MX];
ll res[MX];
vi pos[MX];

void main_() {
	cin >> n;
	forn (i, n) {
		cin >> l[i] >> r[i];
		pos[r[i]].pb(i);
	}
	
	for (int k = 1; k < MX; k++) {
		for (int d : divi[k]) {
			if (d < k)
				update(ft1, d, 1);
			
			if (__gcd(2 * d, k) == d)
				if (2 * d < k)
					update(ft2, 2 * d, 1);
		}
		
		for (int i : divi[k]) {
			if (i < k) {
				int s = 0;
				s += count(ft1, max(    k + 1 - k - i, i + 1), k - 1);
				s += count(ft2, max(2 * k + 1 - k - i, i + 1), k - 1);
				
				update(acu, 1, s);
				update(acu, i + 1, -s);
			}
			
			if (__gcd(2 * i, k) == i)
				if (2 * i < k) {
					i *= 2;
					int s = 0;
					
					s += count(ft1, max(2 * k + 1 - k - i, i + 1), k - 1);
					s += count(ft2, max(2 * k + 1 - k - i, i + 1), k - 1);
					
					update(acu, 1, s);
					update(acu, i + 1, -s);
				}
		}
		
		for (int d : divi[k]) {
			if (d < k)
				update(ft1, d, -1);
			
			if (__gcd(2 * d, k) == d)
				if (2 * d < k)
					update(ft2, 2 * d, -1);
		}
		
		for (int i : pos[k])
			res[i] = comb3(r[i] - l[i] + 1) - query(acu, l[i]);
	}
	
	forn (i, n)
		cout << res[i] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	for (int i = 1; i < MX; i++)
		for (int j = i; j < MX; j += i)
			divi[j].pb(i);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}