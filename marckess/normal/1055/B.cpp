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

const int MX = 100005;
int n, m, l, t, p, d, res = 0;
ll a[MX];
bitset<MX> bs;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> l;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		bs[i] = a[i] > l;
		if (bs[i] && !bs[i-1]) res++;
	}

	while (m--) {
		cin >> t;
		if (t) {
			cin >> p >> d;

			if (a[p] <= l && a[p] + d > l) {
				if (!bs[p-1] && !bs[p+1]) res++;
				if (bs[p-1] && bs[p+1]) res--;
			}

			a[p] += d;
			bs[p] = bs[p] | (a[p] > l);
		} else {
			cout << res << endl;
		}
	}

	return 0;
}