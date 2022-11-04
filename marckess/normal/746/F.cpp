#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#include <bits/extc++.h>
using namespace __gnu_pbds;

typedef tree<ii, null_type, greater<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MX = 2e5+5;
int w, n, k, a[MX], t[MX], res = 0, sa = 0, st = 0;
ordered_set os;

void insert (int i) {
	if (os.size() >= w) {
		ii x = *os.find_by_order(w-1);
		
		if (t[i] >= x.fi) {
			st -= (x.fi + 1) / 2;
			st += x.fi;

			st += (t[i] + 1) / 2;
		} else {
			st += t[i];
		}
	} else {
		st += (t[i] + 1) / 2;
	}

	sa += a[i];
	os.insert(ii(t[i], i));
}

void erase (int i) {
	if (os.size() > w) {
		ii x = *os.find_by_order(w);

		if (t[i] >= x.fi) {
			st -= x.fi;
			st += (x.fi + 1) / 2;

			st -= (t[i] + 1) / 2;
		} else {
			st -= t[i];
		}
	} else {
		st -= (t[i] + 1) / 2;
	}

	sa -= a[i];
	os.erase(ii(t[i], i));
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> w >> k;

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> t[i];

	int i = 0, j = 0;
	while (i < n) {
		j = max(j, i);

		while (j < n) {
			insert(j);

			if (st > k) {
				erase(j);
				break;
			}

			j++;
		}

		res = max(res, sa);
		if (i < j) erase(i);
		i++;
	}

	cout << res << endl;

	return 0;
}