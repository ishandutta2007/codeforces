#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 10000002;
int n, bs[MX], phi[MX], mu[MX], cx[MX], cy[MX];
ll res, cop, cn;
bitset<MX> inx, iny;

void pre () {
	forn(i, MX) {
		mu[i] = 1;
		phi[i] = i;
	}

	bs[1] = -1;
	phi[1] = 0;
	mu[1] = 1;

	for (ll i = 2; i < MX; i++) {
		if (!bs[i]) {
			for (ll j = i; j < MX; j += i) {
				if (!bs[j]) bs[j] = i;
				mu[j] *= -1;
				phi[j] -= phi[j] / i;
			}
			for (ll j = i * i; j < MX; j += i * i)
				mu[j] = 0;
		}
	}
}

int d[MX], m;
void del (int cx[], bitset<MX> &inx, int cy[], int x) {
	inx[x] = 0;

	if (x == 1) {
		cn -= cy[1];
		cx[1]--;
		return;
	}

	d[0] = 1, m = 1; 
	while (x > 1) {
		int p = bs[x];
		while (x % p == 0) x /= p;

		for (int i = 0; i < m; i++)
			d[i + m] = d[i] * p;
		m *= 2;
	}

	for (int i = 0; i < m; i++) {
		int y = d[i];
		cn -= mu[y] * cy[y];
		cx[y]--;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	pre();

	cin >> n;

	for (int i = 2, pre = 1; i <= n; i++) {
		if (2 * bs[i] <= n) {
			res += i - 1 - pre;
			res += phi[i] - pre;
			cop += phi[i] - pre;
		} else {
			pre++;
		}
	}

	for (int i = 1; i <= n; i++)
		if (2 * bs[i] <= n) {
			cx[i] = cy[i] = n / i;
			inx[i] = iny[i] = i - 1;
		} else {
			cx[1]--, cy[1]--;
		}
	inx[1] = 1, cy[1]--;

	cn = 2 * cop + cy[1];

	for (int i = 2, pi = n, pj = n; i * i <= n; i++)
		if (bs[i] == i) {
			for (int j = i; j <= n; j += i)
				if (iny[j])
					del(cy, iny, cx, j);

			while (i * pi > n) {
				if (inx[pi])
					del(cx, inx, cy, pi);
				pi--;
			}

			while (i * pj > n) {
				if (bs[pj] == pj)
					for (int j = pj; j <= n; j += pj)
						if (iny[j])
							del(cy, iny, cx, j);
				pj--;
			}

			cop -= cn;

			for (int j = i; j <= n; j += i)
				if (inx[j])
					del(cx, inx, cy, j);
		}
	res += cop;

	cout << res << endl;

	return 0;
}