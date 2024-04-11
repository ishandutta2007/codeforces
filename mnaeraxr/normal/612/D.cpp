#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k; cin >> n >> k;
	vector<pair<int,int>> ev(2 * n);
	for (int i = 0; i < n; ++i){
		int a, b; cin >> a >> b;
		ev[2 * i] = pii(a, -1);
		ev[2 * i + 1] = pii(b, 1);
	}
	sort(ev.begin(), ev.end());

	vector<pii> ans;
	int tot = 0;
	int prev = -oo;

	for (int i = 0, j; i < 2 * n; i = j){
		for (j = i; j < 2 * n && ev[j].first == ev[i].first && ev[j].second == -1; ++j)
			tot -= ev[j].second;

		if (tot >= k){
			if (prev == -oo) prev = ev[i].first;
		}

		for (; j < 2 * n && ev[j].first == ev[i].first; ++j)
			tot -= ev[j].second;

		if (tot < k) {
			if (prev != -oo){
				ans.push_back(pii(prev, ev[i].first));
				prev = -oo;
			}
		}
	}

	cout << ans.size() << endl;
	for (auto p : ans)
		cout << p.first << " " << p.second << endl;

	return 0;
}