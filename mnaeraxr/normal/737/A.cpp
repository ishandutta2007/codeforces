#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int64,int64> pii;

const int64 oo = 0x3f3f3f3f3f3f3f3f;

int64 check(int64 tank, vector<int64> dist){
	int64 ans = 0, cur = 0;

	for (auto p : dist){
		int64 d = p - cur;
		cur = p;
		if (tank < d) return oo;
		ans += 2 * d - min(d, tank - d);
	}

	return ans;	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int64 n, k, s, t;
	cin >> n >> k >> s >> t;

	vector<pii> car(n), good;

	for (int64 i = 0; i < n; ++i){
		int64 c, v;
		cin >> c >> v;

		car[i] = pii(c, v);
	}

	sort(car.begin(), car.end());

	for (int64 i = 0; i < n; ++i){
		if (i == 0 || car[i].second > good.back().second)
			good.push_back(car[i]);
	}

	vector<int64> dist(k + 1);
	for (int64 i = 0; i < k; ++i)
		cin >> dist[i];

	dist[k] = s;

	sort(dist.begin(), dist.end());

	int64 l = -1, h = (int)good.size() - 1;

	if (check(good[h].second, dist) > t)
		cout << -1 << endl;
	else{
		while (l + 1 < h){
			int64 m = (l + h) >> 1;
			if (check(good[m].second, dist) <= t)
				h = m;
			else
				l = m;
		}
		
		cout << good[h].first << endl;
	}

	return 0;
}