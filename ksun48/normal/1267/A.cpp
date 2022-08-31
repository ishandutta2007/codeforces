#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	using ll = long long;

	int N; cin >> N;
	struct master {
		ll a, b, t;
	};
	vector<master> masters(N);
	for (int i = 0; i < N; i++) {
		cin >> masters[i].a >> masters[i].b >> masters[i].t;
	}

	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> evts;
	for (int i = 0; i < N; i++) {
		evts.push({masters[i].a + masters[i].t, i+1});
	}

	ll ans = 0;
	ll curT = 0;
	set<pair<ll, int>> active;
	while (!evts.empty()) {
		ll nxtT = evts.top().first;
		int i = evts.top().second;
		evts.pop();
		bool isInsert = i > 0;
		i = abs(i) - 1;

		if (!active.empty()) {
			ll v = (nxtT - curT) / active.begin()->first;
			ans += v;
			curT += v * active.begin()->first;
		}
		if (isInsert) {
			curT = max(curT, masters[i].a);
			active.insert({masters[i].t, i});
			evts.push({masters[i].b, -(i+1)});
		} else {
			active.erase({masters[i].t, i});
		}
	}

	cout << ans << '\n';
	return 0;
}