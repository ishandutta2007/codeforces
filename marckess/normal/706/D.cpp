#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define first fi;
#define second se;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vi> vvi;

const ll mx = 1LL << 32;

struct trie {
	trie *s[2];
	int cant;

	trie () {
		s[0] = s[1] = NULL;
		cant = 0;
	}
};

void agregar (string &s, trie *t) {
	for (char c : s) {
		if (t->s[c-'0'] == NULL)
			t->s[c-'0'] = new trie();
		t = t->s[c-'0'];
		t->cant++;
	}
}

void eliminar (string &s, trie *t) {
	for (char c : s) {
		t = t->s[c-'0'];
		t->cant--;
	}
}

ll obtRes (string &s, trie *t) {
	ll res = 0, y = mx;
	for (char c : s) {
		int i = c-'0';
		if (t->s[1-i] != NULL && t->s[1-i]->cant) {
			t = t->s[1-i];
			res += y;
		} else {
			t = t->s[i];
		}
		y /= 2;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int q;
	ll x;
	char c;
	trie *t = new trie();
	string s(33, '0');

	agregar(s, t);

	cin >> q;
	while (q--) {
		cin >> c >> x;

		ll y = mx;
		for (int i = 0; i < 33; i++) {
			s[i] = (x & y) ? '1' : '0';
			y /= 2;
		}
		
		if (c == '+')
			agregar(s, t);
		if (c == '-')
			eliminar(s, t);
		if (c == '?') 
			cout << obtRes(s, t) << endl;
	}
	
	return 0;
}