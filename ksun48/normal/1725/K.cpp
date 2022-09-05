#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N;
	cin >> N;
	vector<int> A(N);
	for(int& x : A) cin >> x;

	map<int, int> height_to_group;
	vector<int> group_height;

	vector<vector<int> > group_contents; // superset of group contents
	vector<int> building_group(N);
	auto create_group = [&](int H){
		if(height_to_group.count(H)) return;
		int g = (int)group_contents.size();
		height_to_group[H] = g;
		group_contents.push_back({});
		group_height.push_back(H);
	};
	auto set_group = [&](int Hold, int Hnew){
		if(Hold == Hnew) return;
		create_group(Hold);
		create_group(Hnew);
		int group1 = height_to_group[Hold], group2 = height_to_group[Hnew];
		if(group_contents[group2].size() > group_contents[group1].size()){
			swap(group1, group2);
		}
		for(int i : group_contents[group2]){
			if(building_group[i] != group2){
				continue;
			}
			building_group[i] = group1;
			group_contents[group1].push_back(i);
		}
		group_height[group1] = Hnew;
		height_to_group.erase(Hold);
		height_to_group[Hnew] = group1;
	};
	for(int i = 0; i < N; i++){
		create_group(A[i]);
		int g = height_to_group[A[i]];
		group_contents[g].push_back(i);
		building_group[i] = g;
	}
	int Q;
	cin >> Q;
	while(Q--){
		int type;
		cin >> type;
		if(type == 1){
			int i, H;
			cin >> i >> H;
			i--;
			// k -> w
			create_group(H);
			int g = height_to_group[H];
			group_contents[g].push_back(i);
			building_group[i] = g;
		} else if(type == 2){
			int i;
			cin >> i;
			i--;
			cout << group_height[building_group[i]] << '\n';
		} else if(type == 3){
			int l, r;
			cin >> l >> r;
			while(true){
				auto x = height_to_group.lower_bound(l);
				if(x == height_to_group.end()) break;
				auto [h, id] = *x;
				if(h > r) break;
				if(abs(h-l) < abs(h-r)){
					set_group(h, l-1);
				} else {
					set_group(h, r+1);
				}
			}
		} else assert(false);
	}
}