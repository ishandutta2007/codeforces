#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 100005;

struct DS {
	int p[MX], rk[MX], tam[MX];

	void init (int n) {
		for (int i = 0; i < n; i++) {
			p[i] = i;
			rk[i] = 0;
			tam[i] = 1;
		}
	}

	int parent (int a) {
		return p[a] == a ? a : p[a] = parent(p[a]);
	}

	bool joint (int a, int b) {
		a = parent(a), b = parent(b);

		if (a == b)
			return 0;

		if (rk[a] > rk[b]) {
			tam[a] += tam[b];
			p[b] = a;
		} else {
			tam[b] += tam[a];
			p[a] = b;
			if (rk[a] == rk[b])
				rk[b]++;
		}

		return 1;
	}
}ds;

int n, a[MX], q[MX], acu[MX];
bitset<MX> us;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    	cin >> a[i];

    iota(q, q+n, 0);
    sort(q, q+n, [&] (int x, int y) {
    	return a[x] < a[y];
    });

    ds.init(n);

    int i = 0, mx = 0, res = 0, cn = 0;
    while (i < n) {
    	int act = a[q[i]], ult = q[i];

    	while (i < n && a[q[i]] == act) {
    		int u = q[i];
    		cn++;
    		acu[1]++;

    		if (u > 0 && us[u-1]) {
    			acu[ds.tam[ds.parent(u-1)]]--;
    			acu[ds.tam[ds.parent(u)]]--;
    			cn--;

    			ds.joint(u-1, u);
    			acu[ds.tam[ds.parent(u)]]++;
    		}

    		if (u < n - 1 && us[u+1]) {
    			acu[ds.tam[ds.parent(u+1)]]--;
    			acu[ds.tam[ds.parent(u)]]--;
    			cn--;

    			ds.joint(u+1, u);
    			acu[ds.tam[ds.parent(u)]]++;
    		}
    		us[u] = 1;
    		i++;
    	}

    	if (acu[ds.tam[ds.parent(ult)]] == cn) {
    		if (cn > mx) {
    			mx = cn;
    			res = act + 1;
    		}
    	}
    }

    cout << res << endl;

    return 0;
}