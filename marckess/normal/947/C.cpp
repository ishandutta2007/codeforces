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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 300005;

struct Trie {
	Trie *sig[2];
	int cn;

	Trie() {
		cn = 0;
		sig[0] = sig[1] = 0;
	}
};

Trie *trie = new Trie;

void insert (int n) {
	Trie *t = trie;

	for (int i = 29; i >= 0; i--) {
		int s = bool(n & (1 << i));
		t->cn++;
		if (!t->sig[s])
			t->sig[s] = new Trie();
		t = t->sig[s];
	}
	t->cn++;
}

int find (int n) {
	Trie *t = trie;
	int res = 0;

	for (int i = 29; i >= 0; i--) {
		int s = bool(n & (1 << i));
		t->cn--;
		if (t->sig[s] && t->sig[s]->cn) {
			res |= (s << i);
			t = t->sig[s];
		} else {
			res |= ((s ^ 1) << i);
			t = t->sig[1-s];
		}
	}

	t->cn--;
	return res;
}

int n, a[MX], p;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++) {
		cin >> p;
		insert(p);
	}

	for (int i = 0; i < n; i++)
		cout << (a[i] ^ find(a[i])) << " ";
	cout << endl;

	return 0;
}