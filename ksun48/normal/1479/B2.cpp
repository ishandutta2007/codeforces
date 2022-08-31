#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;

	int cur = 0;
	int cnt = 0;
	vector<int> rle;
	for(int i = 0; i < (int)a.size(); i++){
		if(cur != a[i]){
			if(cnt) rle.push_back(cur);
			cnt = 0;
			cur = a[i];
		}
		cnt++;
	}
	if(cnt) rle.push_back(cur);
	int ans = (int)rle.size();
	set<int> seen;
	for(int i = 0; i < (int)rle.size(); i++){
		if(seen.count(rle[i])){
			ans--;
			seen = {};
			seen.insert(rle[i-1]);
		}
		seen.insert(rle[i]);
	}
	cout << ans << '\n';
}