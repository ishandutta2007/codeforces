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

const int MX = 200'005;
const ll inf = 1'000'000'000'000'000'000LL;

struct Trie {
	Trie *sig[2];
	vi st;

	Trie () { memset(sig, 0, sizeof(sig)); }
	int n;
};

int n, a;
Trie *trie = new Trie();
vi st;

void insert (Trie *t, int n) {
	for (int i = 29; i >= 0; i--) {
		int s = (n & (1 << i));

		if (!t->sig[bool(s)])
			t->sig[bool(s)] = new Trie();

		t = t->sig[bool(s)];
		t->st.push_back(n);
	}

	t->n = n;
}

ll find (Trie *t, int n, int i) {

	while (i >= 0) {
		int s = n & (1 << i);

		if (t->sig[bool(s)])
			t = t->sig[bool(s)];
		else
			t = t->sig[1-bool(s)];
		
		i--;
	}

	return t->n;
}

ll obtRes (Trie *t, int i) {
	if (i < 0 || !t)
		return 0;
	ll res = 0;

	if (t->sig[0] && t->sig[1]) {
		res = inf;
		for (int x : t->sig[0]->st)
			res = min(res, x ^ find(t->sig[1], x, i-1));
	}

	return obtRes(t->sig[0], i-1) + obtRes(t->sig[1], i-1) + res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		st.push_back(a);
	}
	
	sort(ALL(st));
	st.erase(unique(ALL(st)), st.end());

	for (int x : st)
		insert(trie, x);

	cout << obtRes(trie, 29) << endl;

	return 0;
}