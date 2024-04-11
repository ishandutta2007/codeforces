#include <bits/stdc++.h>
using namespace std;

const int B = 21;


int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		assert(0 <= a[i] && a[i] < (1 << B));
	}
	vector<char> cnt(1 << B, 0);
	reverse(a.begin(), a.end());

	vector<int> reach(1 << B, n);
	vector<bool> seen(1 << B, false);
	for(int i = 0; i < n; i++){
		vector<int> bfs;
		bfs.push_back(a[i]);
		int s = 0;
		while(s < (int)bfs.size()){
			int v = bfs[s];
			s += 1;
			if(cnt[v] >= 2) continue;
			if(seen[v]) continue;
			seen[v] = true;
			cnt[v] ++;
			if(cnt[v] == 2){
				reach[v] = i;
			}
			for(int j = 0; j < B; j++){
				if((1 << j) & v){
					bfs.push_back(v ^ (1 << j));
				}
			}
		}
		for(int x : bfs){
			seen[x] = false;
		}
	}

	int ans = 0;
	int tot = (1 << B) - 1;
	for(int b = B-1; b >= 0; b--){
		int test_mask = ans ^ (1 << b);
		vector<int> new_reach(1 << B);
		for(int i = 0; i < (1 << B); i++){
			new_reach[i] = reach[i & test_mask];
		}
		bool works = false;
		for(int i = 0; i < n; i++){
			if(new_reach[tot ^ a[i]] < i){
				works = true;
			}
		}
		if(works){
			ans = test_mask;
		}
	}
	cout << ans << '\n';
}