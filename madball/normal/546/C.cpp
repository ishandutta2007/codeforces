#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
using namespace std;
typedef long long ll;
const ll inf = 1e+18;

template<typename T> struct Trie {
	Trie *link[2][2];
	T val;
	Trie() {
		for (ll i = 0; i < 4; i++)
			link[i & 1][i >> 1] = NULL;
	}
	T get(ll x, ll y) {
		if (x + y) {
			Trie *next = link[x & 1][y & 1];
			if (next == NULL)
				return T();
			else
				return next->get(x >> 1, y >> 1);
		}
		else
			return val;
	}
	void set(ll x, ll y, T v) {
		if (x + y) {
			Trie *&next = link[x & 1][y & 1];
			if (next == NULL)
				next = new Trie();
			next->set(x >> 1, y >> 1, v);
		}
		else
			val = v;
	}
};

struct Stack {
	queue<ll> cards;
	ll hash;
	Stack(): hash(0) {}
	ll pop() {
		ll front = cards.front();
		cards.pop();
		hash >>= 4;
		return front;
	}
	void push(ll card) {
		hash += card << (4 * cards.size());
		cards.push(card);
	}
};

int main() {
	/*ifstream in("input.txt");
	ofstream out("output.txt");*/

	ll n, k1, k2, cur, i, c1, c2, res = 0;
	Stack s1, s2;
	cin >> n >> k1;
	for (i = 0; i < k1; i++) {
		cin >> cur;
		s1.push(cur);
	}
	cin >> k2;
	for (i = 0; i < k2; i++) {
		cin >> cur;
		s2.push(cur);
	}

	Trie<bool> been;
	been.set(s1.hash, s2.hash, true);
	while (((bool)s1.hash) && ((bool)s2.hash)) {
		c1 = s1.pop();
		c2 = s2.pop();
		if (c1 > c2) {
			s1.push(c2);
			s1.push(c1);
		}
		else {
			s2.push(c1);
			s2.push(c2);
		}
		if (been.get(s1.hash, s2.hash)) {
			cout << -1;
			return 0;
		}
		else
			been.set(s1.hash, s2.hash, true);
		res++;
	}
	cout << res << ' ' << (s1.hash ? 1 : 2);

	return 0;
}