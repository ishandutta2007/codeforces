#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int64> vi;

const int64 oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200010;

int64 n, m, k, s;
pii coin[2][maxn];
vector<pii> gadg[2];
vector<pii> buy;

int64 solve(int64 d, bool f = false){
	int64 ans = 0;
	for (int64 p1 = 0, p2 = 0; p1 + p2 < k;){
		if (p1 == gadg[0].size()){
			if (f) buy.push_back(pii(gadg[1][p2].second, coin[1][d].second));
			ans += coin[1][d].first * gadg[1][p2++].first;
		}
		else if (p2 == gadg[1].size()){
			if (f) buy.push_back(pii(gadg[0][p1].second, coin[0][d].second));
			ans += coin[0][d].first * gadg[0][p1++].first;
		}
		else{
			int64 c0 = coin[0][d].first * gadg[0][p1].first;
			int64 c1 = coin[1][d].first * gadg[1][p2].first;
			
			if (c0 < c1){
				ans += c0;
				if (f) buy.push_back(pii(gadg[0][p1].second, coin[0][d].second));
				++p1;
			}
			else{
				ans += c1;
				if (f) buy.push_back(pii(gadg[1][p2].second, coin[1][d].second));
				++p2;
			}
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k >> s;

	coin[0][0] = coin[1][0] = pii(oo, 0);
	for (int c = 0; c < 2; ++c)
		for (int i = 1; i <= n; ++i){
			cin >> coin[c][i].first;
			coin[c][i].second = i;
			coin[c][i] = min(coin[c][i], coin[c][i - 1]);
		}

	for (int i = 0; i < m; ++i){
		int64 t, v; cin >> t >> v;
		gadg[t - 1].push_back(pii(v, i + 1));
	}

	sort(gadg[0].begin(), gadg[0].end());
	sort(gadg[1].begin(), gadg[1].end());

	if (solve(n) > s) cout << -1 << endl;
	else{
		int64 lo = 0, hi = n;
		while (lo + 1 < hi){
			int64 mid = (lo + hi) / 2;
			if (solve(mid) > s) lo = mid;
			else hi = mid;
		}
		solve(hi, true);
		cout << hi << endl;
		for (int i = 0; i < k; ++i)
			cout << buy[i].first << " " << buy[i].second << endl;
	}

	return 0;
}