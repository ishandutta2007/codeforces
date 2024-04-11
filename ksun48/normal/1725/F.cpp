#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N;
	cin >> N;
	vector<int> L(N), R(N);
	const int B = 30;
	vector<map<int, int> > freq(B);
	vector<int> plus(B);
	for(int i = 0; i < N; i++){
		cin >> L[i] >> R[i];
		R[i]++;
	}
	vector<int> ans(B, 0);
	for(int b = 0; b < B; b++){
		vector<pair<int, int> > evts;
		for(int i = 0; i < N; i++){
			int len = (1 << b);
			if(R[i] - L[i] >= len){
				evts.push_back({0, 1});
				evts.push_back({len, -1});
			} else if((L[i] % len) < (R[i] % len)){
				evts.push_back({L[i] % len, 1});
				evts.push_back({R[i] % len, -1});
			} else {
				evts.push_back({0, 1});
				evts.push_back({len, -1});
				evts.push_back({L[i] % len, 1});
				evts.push_back({R[i] % len, -1});
			}
		}
		sort(evts.begin(), evts.end());
		int idx = 0;
		int cur = 0;
		while(idx < (int)evts.size()){
			int j = idx;
			while(evts[j].first == evts[idx].first){
				cur += evts[j].second;
				j++;
			}
			ans[b] = max(ans[b], cur);
			idx = j;
		}
	}
	int Q;
	cin >> Q;
	while(Q--){
		int z;
		cin >> z;
		cout << ans[__builtin_ctz(z)] << '\n';
	}
}