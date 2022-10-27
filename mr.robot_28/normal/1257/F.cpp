#include<bits/stdc++.h>
using namespace std;
const int const1 = 1e9 + 7;
const int const2 = 998244353;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector <int> cnt(n);
	vector <pair <pair <int, int>, int> > h1;
	for(int x = 0; x < (1 << 15); x++)
	{
		int mask = (1 << 15) - 1;
		int mincnt = 1e9;
		for(int i = 0; i < n; i++){
			cnt[i] = __builtin_popcount((a[i] & mask) ^ x);
			mincnt = min(mincnt, cnt[i]);
		}
		pair <int, int> hash = make_pair(0, 0);
		for(int i = 0; i < n; i++)
		{
			hash.first = (hash.first * 17 + cnt[i] - mincnt) % const1;
			hash.second = (hash.second * 17 + cnt[i] - mincnt) % const2;
		}
		h1.push_back({hash, x});
	}
	sort(h1.begin(), h1.end());
	for(int x = 0; x < (1 << 15); x++)
	{
		int x1 = x * (1 << 15);
		int mask = (1 << 15) - 1;
		mask = mask * (1 << 15);
		int maxcnt = 0;
		for(int i = 0; i < n; i++){
			cnt[i] = __builtin_popcount((a[i] & mask) ^ x1);
			maxcnt = max(maxcnt, cnt[i]);
		}
		pair <int, int> hash = make_pair(0, 0);
		for(int i = 0; i < n; i++)
		{
			hash.first = (hash.first * 17 + maxcnt - cnt[i]) % const1;
			hash.second = (hash.second * 17 + maxcnt - cnt[i]) % const2;
		}
		int ind = lower_bound(h1.begin(), h1.end(), make_pair(hash, 0)) - h1.begin();
		if(ind != h1.size() && h1[ind].first == hash)
		{
			cout << x1 + h1[ind].second;
			return 0;
		}
	}
	cout << -1;
    return 0;
}