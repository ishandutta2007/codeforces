#include <bits/stdc++.h>

//#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
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

const int MX = 100005, SQ = 100;
int n, bs[MX], res = 1, cn;
vi p;

int qa (int a) {
	cout << "A " << a << endl;
	int r;
	cin >> r;
	return r;
}

int qb (int a) {
	cout << "B " << a << endl;
	int r;
	cin >> r;
	return r;
}

void find (int i) {
	while (i >= 0) {
		if (p[i] <= n && qa(p[i])) {
			res *= p[i];
			return;
		}
		i--;
	}
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	for (ll i = 2; i < MX; i++)
		if (!bs[i]) {
			p.pb(i);
			for (ll j = i * i; j < MX; j += i)
				bs[j] = 1;
		}

	cin >> n;

	int i = 0;

	while (p[i] * p[i] <= n) {
		qb(p[i]);

		ll pot = p[i];
		while (pot <= n && qa(pot)) pot *= p[i];

		res *= pot / p[i];
		i++;
	}

	int ex = qa(1);
	
	while (i < p.size() && p[i] <= n) {
		if (i % SQ == 0) {
			int act = qa(1);

			if (act != ex) {
				find(i - 1);
				ex = act;
				break;
			}

			ex = act;
		}

		int d = qb(p[i]);
		if (d > 1) res *= p[i];
		ex--;
		i++;
	}

	int act = qa(1);

	if (act != ex)
		find(i - 1);

	cout << "C " << res << endl;

	return 0;
}