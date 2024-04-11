#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int Q = 5 * (int)1e5;
int ans[Q];

struct Seg {
	vector<int> vals;
	int h = 1;

	Seg(int n) {
		while(h < n) h <<= 1;
		vals.resize(2*h, 0);
	}

	void activate(int i) {
		for (i += h; i > 0; i /= 2) vals[i] += 1;
	}
	int getKth(int k) {
		int i = 1;
		while(i < h) {
			i *= 2;
			if (vals[i] < k) {
				k -= vals[i];
				++i;
			}
		}
		return i-h;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, q;
	cin >> n >> m >> q;

	vector<ll> cou(m, 0);
	for (int i = 0; i < n; ++i) {
		int j;
		cin >> j;
		++cou[j-1];
	}

	vector<pair<ll, int>> evs(m);
	for (int i = 0; i < m; ++i) {
		evs[i] = {cou[i], i};
	}
	sort(evs.begin(), evs.end());

	vector<pair<ll, int>> ques(q);
	for (int i = 0; i < q; ++i) {
		cin >> ques[i].first;
		ques[i].second = i;
	}
	sort(ques.begin(), ques.end());

	Seg act(m);
	ll t = n;
	ll h = 0;
	int ei = 0;
	for (int qi = 0; qi < q; ++qi) {
		ll qt = ques[qi].first;
		while(ei < evs.size()) {
			ll dt = qt - t;
			ll nt = (ll)(evs[ei].first - h) * ei;
			if (nt < dt) {
				t += nt;
				h = evs[ei].first;
				act.activate(evs[ei].second);
				++ei;
			} else break;
		}
		ll dt = qt - t - 1;
		ans[ques[qi].second] = 1 + act.getKth(1 + dt % ei);
	}

	for (int i = 0; i < q; ++i) cout << ans[i] << '\n';
}