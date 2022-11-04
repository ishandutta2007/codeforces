#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

struct List {
	List *sig, *ant;
	int x, pos;
	List () {}
	List (int x, int pos, List *sig, List *ant) : x(x), pos(pos), sig(sig), ant(ant) {}
	void impr () { cout << x << " " << pos << endl; }

	void del () {
		if (ant) ant->sig = sig;
		if (sig) sig->ant = ant;
	}
};

const int MX = 200005;
int n, q, a[MX], cn[MX], f = 0;
List *pos[MX], *it = 0, *l = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(pos, 0, sizeof(pos));

	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (!it) {
			it = new List(a[i], i, 0, 0);
			l = it;
		}
		else {
			it->sig = new List(a[i], i, 0, it);
			it = it->sig;
		}
		if (!pos[a[i]]) pos[a[i]] = it;
		cn[a[i]]++;
	}

	if (!cn[q]) {
		if (!cn[0]) {
			cout << "NO" << endl;
			return 0;
		}
		f = 1;
	}

	for (int i = q; i >= 1; i--) {
		it = pos[i];
		while (cn[i]) {
			cn[it->x]--;
			if (!it->x) {
				if (f) { a[it->pos] = q; f = 0; }
				else a[it->pos] = i;
			}
			else if (it->x != i) {
				cout << "NO" << endl;
				return 0;
			}
			it->del();
			it = it->sig;
		}
		if (cn[i]) {
			cout << "NO" << endl;
			return 0;
		}
	}

	if (f && !cn[0]) {
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	for (int i = 0; i < n; i++) {
		if (a[i]) cout << a[i] << " ";
		else if (f) { cout << q << " "; f = 0; }
		else cout << 1 << " ";
	}
	cout << endl;

	return 0;
}