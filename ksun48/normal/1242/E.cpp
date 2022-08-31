#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int,int> > _a(n);
	for(int i = 0; i < n; i++){
		cin >> _a[i].first;
		_a[i].second = i;
	}

	sort(_a.begin(), _a.end());
	reverse(_a.begin(), _a.end());

	vector<int> a(n);
	for(int i = 0; i < n; i++) a[i] = _a[i].first;

	vector<vector<int> > ans_ids(n);

	vector<int> cur_ids;
	int next_id = 0;
	for(int x = 0; x < a.front(); x++){
		cur_ids.push_back(next_id);
		next_id++;
	}
	ans_ids[_a[0].second] = cur_ids;

	set<pair<int,int> > used;
	for(size_t i = 0; i < cur_ids.size(); i++){
		used.insert({cur_ids[i], cur_ids[(i+1) % (cur_ids.size())]});
	}

	for(int j = 1; j < (int)a.size(); j++){
		int lb = 3;
		if(j + 1 < (int)a.size()) lb = a[j+1];
		// don't go under lb
		int x = (int)cur_ids.size();
		int y = a[j];
		int k = 0;
		while(x + y - 2 >= lb && x >= 2 && y >= 2){
			x--; y--;
			k++;
		}
		assert(k >= 1);
		if(y == 1){
			// do some rotatos
			while(true){
				int r = cur_ids.front();
				int s = cur_ids[cur_ids.size() - (a[j] - 1)];
				if(used.count({r, s}) || used.count({s, r})){
					cur_ids.push_back(cur_ids.front());
					cur_ids.erase(cur_ids.begin());
				} else {
					break;
				}
			}
		}
		vector<int> new_poly;
		new_poly.push_back(cur_ids.front());
		cur_ids.push_back(-2);
		for(int i = 0; i < k; i++){
			cur_ids.pop_back();
			new_poly.push_back(cur_ids.back());
		}
		for(int i = 0; i < y-1; i++){
			new_poly.push_back(next_id);
			cur_ids.push_back(next_id);
			next_id++;
		}
		for(size_t i = 0; i < new_poly.size(); i++){
			used.insert({new_poly[i], new_poly[(i+1) % new_poly.size()]});
		}
		ans_ids[_a[j].second] = new_poly;
	}
	cout << next_id << '\n';
	for(vector<int> x : ans_ids){
		for(int y : x){
			cout << y + 1 << ' ';
		}
		cout << '\n';
	}
}