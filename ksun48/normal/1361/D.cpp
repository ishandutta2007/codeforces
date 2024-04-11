#include <bits/stdc++.h>
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	int k;
	cin >> k;
	using ll = long long;
	using ld = long double;
	map<pair<ll, ll>, vector<ld> > dists_map;
	for(int i = 0; i < n; i++){
		ll x, y;
		cin >> x >> y;
		if(x == 0 && y == 0) continue;
		ll g = __gcd(abs(x), abs(y));
		ll ax = x / g;
		ll ay = y / g;
		ld dist = sqrt(ld(x * x + y * y));
		dists_map[{ax, ay}].push_back(dist);
	}
	vector<vector<ld> > dists;
	for(auto r : dists_map){
		sort(r.second.begin(), r.second.end());
		dists.push_back(r.second);
	}
	int d = (int)dists.size();
	vector<pair<ld, pair<int,int> > > cands;
	for(int j = 0; j < d; j++){
		vector<ld>& v = dists[j];
		int len = (int)v.size();
		for(int i = -1; i < len; i++){
			int a = len-1-i;
			ld score = (i == -1 ? 0 : v[i]) * (k-1-a-a);
			cands.push_back({score, {j, i}});
		}
	}
	sort(cands.rbegin(), cands.rend());
	cands.resize(k);
 
	vector<int> cnt(d, 0);
	bool fail = false;
	for(auto g : cands){
		if(g.second.second == -1) fail = true;
		int j = g.second.first;
		cnt[j]++;
	}
	ld best = 0;
	if(!fail){
		ld ans = 0;
		for(int j = 0; j < d; j++){
			vector<ld>& v = dists[j];
			int len = (int)v.size();
			int cur = cnt[j];
			ld last = 0;
			for(int i = 0; i < len; i++){
				ans += ld(cur) * ld(k - cur) * (v[i] - last);
				if(i >= len - cnt[j]) cur--;
				last = v[i];
			}
			assert(cur == 0);
		}
		best = ans;
	} else {
		int biggest = 0;
		for(int j = 0; j < d; j++){
			if(dists[j].size() > dists[0].size()) biggest = j;
		}
		ld ans = 0;
		int nleft = k;
		for(int j = 0; j < d; j++){
			if(j == biggest) continue;
			vector<ld>& v = dists[j];
			int len = (int)v.size();
			int cur = len;
			nleft -= len;
			ld last = 0;
			for(int i = 0; i < len; i++){
				ans += ld(cur) * ld(k - cur) * (v[i] - last);
				cur--;
				last = v[i];
			}
			assert(cur == 0);
		}
		int bottom = k/2;
		nleft -= bottom + 1;
		{
			vector<ld>& v = dists[biggest];
			int len = (int)v.size();
			ld last = 0;
			int cur = nleft + bottom;
			for(int i = 0; i < len; i++){
				ans += ld(cur) * ld(k - cur) * (v[i] - last);
				if(i >= len - bottom || i < nleft) cur--;
				last = v[i];
			}
		}
		best = ans;
	}
	cout << fixed << setprecision(15) << best << '\n';
}