#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	cout << "? " << 1 << '\n';
	cout << flush;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	vector<int> odd, even;
	for(int i = 1; i < n; i++){
		if(a[i] % 2 == 0){
			even.push_back(i);
		} else {
			odd.push_back(i);
		}
	}
	bool z = (odd.size() < even.size());
	even.push_back(0);
	vector<int> r = z ? odd : even;
	set<pair<int,int> > edges;
	for(int i : r){
		vector<int> res;
		if(i == 0){
			res = a;
		} else {
			cout << "? " << (i+1) << '\n';
			cout << flush;
			res.resize(n);
			for(int& x : res) cin >> x;
		}
		for(int j = 0; j < n; j++){
			if(res[j] == 1){
				edges.insert({min(i, j), max(i, j)});
			}
		}
	}
	cout << "!" << '\n';
	for(auto [u, v] : edges){
		cout << (u+1) << ' ' << (v+1) << '\n';
	}
}