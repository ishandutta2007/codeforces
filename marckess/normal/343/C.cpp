#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 100005;
int n, m;
ll h[MX], p[MX];

ll dits (ll x, ll a, ll b) {
	if (a <= x && x <= b) {
		ll h = abs(x - a), g = abs(x - b);
		return 2 * h + 2 * g - max(g, h);
	}
	return abs(b - x);
}

bool esPos (ll t) {
	int j = 0;

	for (int i = 0; i < n; i++) {
		if (j < m && p[j] <= h[i])
			if (abs(p[j] - h[i]) > t)
				return 0;

		int act = j;
		while (j < m && (p[j] <= h[i] || dits(h[i], p[act], p[j]) <= t))
			j++;
	}

	return j == m;
}

ll obtRes () {
	ll i = 0, j = 1e11, rep = 40;

	while (rep--) {
		ll m = (i+j)/2;
		if (esPos(m))
			j = m;
		else
			i = m;
	}

	if (esPos(i))
		return i;
	return j;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    	cin >> h[i];

    for (int i = 0; i < m; i++)
    	cin >> p[i];

    cout << obtRes() << endl; 

    return 0;
}