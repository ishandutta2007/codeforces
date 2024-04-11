#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

PII v[3];
vector<pair<PII, PII> > ans;

int main()
{
	rep(i, 3) cin >> v[i].first >> v[i].second;
	sort(v, v + 3);
	int mn = 1e9, mx = -1e9;
	rep(i, 3) {
		mn = min(mn, v[i].second); mx = max(mx, v[i].second);
	}
	if(mn != mx) ans.push_back(MP(MP(v[1].first, mn), MP(v[1].first, mx)));
	for(int i = 0; i <= 2; i += 2) if(v[i].first != v[1].first) ans.push_back(MP(MP(v[1].first, v[i].second), v[i]));
	printf("%d\n", (int)ans.size());
	rep(i, ans.size()) printf("%d %d  %d %d\n", ans[i].first.first, ans[i].first.second, ans[i].second.first, ans[i].second.second);
	return 0;
}