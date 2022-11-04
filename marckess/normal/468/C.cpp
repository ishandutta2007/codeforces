#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const ll lim = 2e18;
ll a;
string s;
ll mem[20][165][2];

ll dp (int i, int j, int f) {
	if (i == s.size()) return j;
	
	ll &res = mem[i][j][f];
	if (res != -1) return res;
	res = 0;
	
	forn (d, 10) if (d <= s[i] - '0' || f) {
		res += dp(i + 1, j + d, d < s[i] - '0' || f);
		if (res > lim)
			res = lim;
	}
	
	return res;
}

bool esPos (ll m) {
	memset(mem, -1, sizeof(mem));
	s = to_string(m);
	return dp(0, 0, 0) >= a;
}

ll f (ll n) {
	ll res = 0;
	while (n) {
		res += n % 10;
		n /= 10;
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> a;
	
	ll i = 1, j = 1e18, rep = 64;
	
	while (rep--) {
		ll m = (i + j) / 2;
		if (esPos(m)) j = m;
		else i = m;
	}
	
	esPos(j);
	ll cn = dp(0, 0, 0);
	i = 1;
	
	while (cn > a) {
		cn -= f(i);
		i++;
		while (cn < a) {
			j++;
			cn += f(j);
		}
	}
	
	cout << i << " " << j << endl;
	
	return 0;
}