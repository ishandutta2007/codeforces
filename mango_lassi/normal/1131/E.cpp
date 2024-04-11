#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const ll MAX = (int)1e9 + 7;
const int C = 26;
ll lens[C];
bool exs[C];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int it = 0; it < n; ++it) {
		string txt;
		cin >> txt;

		int m = txt.size();
		vector<int> str(m);
		for (int j = 0; j < m; ++j) str[j] = txt[j] - 'a';

		int cs = str[0];
		ll ls = 1;
		for (int i = 1; i < m; ++i) {
			if (str[i] != cs) break;
			++ls;
		}

		int ce = str[m-1];
		ll le = 1;
		for (int i = m-2; i >= 0; --i) {
			if (str[i] != ce) break;
			++le;
		}

		if (ls == m) {
			ll seq = m * (lens[cs]+1) + lens[cs];
			if (seq > MAX) seq = MAX;

			for (int c = 0; c < C; ++c) lens[c] = exs[c];
			lens[cs] = seq;
		} else {
			for (int c = 0; c < C; ++c) lens[c] = exs[c];
			int cur = str[0];
			ll cl = 1;
			for (int i = 1; i < m; ++i) {
				if (str[i] != cur) {
					lens[cur] = max(lens[cur], cl);
					cl = 1;
					cur = str[i];
				} else {
					++cl;
				}
			}
			lens[cur] = max(lens[cur], cl);
			if (cs == ce) {
				if (exs[cs]) lens[cs] = max(lens[cs], le + 1 + ls);
			} else {
				if (exs[cs]) lens[cs] = max(lens[cs], ls + 1);
				if (exs[ce]) lens[ce] = max(lens[ce], le + 1);
			}
		}
		for (auto c : str) exs[c] = true;
	}

	ll res = 0;
	for (int i = 0; i < C; ++i) res = max(res, lens[i]);
	cout << res << '\n';
}