#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve(){
	int n;
	ll s;
	cin >> n >> s;
	vector<ll> a(n);
	for(ll& x : a) cin >> x;
	vector<ll> psums(n+1, 0);
	for(int i = 0; i < n; i++){
		psums[i+1] = psums[i] + a[i];
	}
	vector<int> mins;
	pair<int, int> best = {-1, -1};
	mins.push_back({n});
	for(int i = n-1; i >= 0; i--){
		while(!mins.empty() && psums[mins.back()] >= psums[i]) mins.pop_back();
		mins.push_back(i);
		int st = -1;
		int en = (int)mins.size();
		while(st + 1 < en){
			int mid = (st + en) / 2;
			if(s + psums[mins[mid]] - psums[i] < 0){
				st = mid;
			} else {
				en = mid;
			}
		}
		int goal = (st == -1) ? n : (mins[st] - 1);
		if(goal - i > best.second - best.first){
			best = {i, goal};
		}
	}
	if(best.first == -1){
		cout << -1 << '\n';
	} else {
		cout << (best.first + 1) << ' ' << best.second << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}