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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000005;
int n, p, x, y, s[MX];
ll k, a[MX], w, res = 0;
vii v(2*MX), es(2*MX), tv(2*MX), tes(2*MX);

#define cn(a,b) (ll)max(0, (b)-(a)+1)
#define d1 v[j].fi
#define d2 v[j].se
#define e1 es[j].fi
#define e2 es[j].se

void sig (int l, int r, int j) {
	int temp = l;
	while (l <= r && !(a[l] & (1ll << j))) l++;
	s[temp] = l;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		cin >> p >> w;
		a[i] = a[p-1] ^ w;
	}

	sort(a, a+n);

	x = 1;
	v[0] = {0, n-1};
	es[0] = {0, n-1};

	for (int i = 61; i >= 0; i--) {
		for (int j = 0; j < x; j++) {
			sig(d1, d2, i);
		}

		ll acu = 0;

		for (int j = 0; j < x; j++) {
			acu += cn(d1, s[d1]-1) * cn(e1, s[e1]-1);
			acu += cn(s[d1], d2) * cn(s[e1], e2);
		}

		y = 0;
		if (acu >= k) {
			
			for (int j = 0; j < x; j++) {

				if (d1 <= s[d1] - 1 && e1 <= s[e1] - 1) {
					tv[y] = {d1, s[d1] - 1};
					tes[y] = {e1, s[e1] - 1};
					y++;
				}

				if (s[d1] <= d2 && s[e1] <= e2) {
					tv[y] = {s[d1], d2};
					tes[y] = {s[e1], e2};
					y++;
				}
			}
		} else {
			k -= acu;
			res |= (1ll << i);

			for (int j = 0; j < x; j++) {
				if (d1 <= s[d1] - 1 && s[e1] <= e2) {
					tv[y] = {d1, s[d1] - 1};
					tes[y] = {s[e1], e2};
					y++;

					tv[y] = tes[y-1];
					tes[y] = tv[y-1];
					y++;
				}
			}
		}

		swap(x, y);
		swap(v, tv);
		swap(es, tes);
	}

	cout << res << endl;

	return 0;
}