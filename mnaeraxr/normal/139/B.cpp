#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<pii> room(n);
	for (int i = 0; i < n; ++i){
		int u, v, h;
		cin >> u >> v >> h;
		room[i] = pii(2 * (u + v), h);
	}

	int m; cin >> m;
	vector<pii> rollDim(m);
	vector<int> rollPrc(m);
	for (int i = 0; i < m; ++i)
		cin >> rollDim[i].first >> rollDim[i].second >> rollPrc[i];

	int64 ans = 0;
	for (int i = 0; i < n; ++i){
		int64 cur = -1; 
		for (int j = 0; j < m; ++j){
			if (rollDim[j].first < room[i].second) continue;
			int l = rollDim[j].first / room[i].second * rollDim[j].second;
			int64 val = (room[i].first + l - 1) / l * rollPrc[j];
			if (cur == -1 || val < cur)
				cur = val;
		}
		ans += cur;
	}

	cout << ans << endl;

	return 0;
}