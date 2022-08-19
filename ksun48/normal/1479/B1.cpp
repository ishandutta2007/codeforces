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
	vector<pair<int,int>> rle;
	for(int i = 0; i < (int)a.size(); i++){
		if(cur != a[i]){
			if(cnt) rle.push_back({cur, cnt});
			cnt = 0;
			cur = a[i];
		}
		cnt++;
	}
	if(cnt) rle.push_back({cur, cnt});
	int ans = 0;
	int k = (int)rle.size();
	int last2 = -1;
	for(int i = 0; i < k; i++){
		ans += min(2, rle[i].second);
		if(rle[i].second >= 2){
			if(last2 >= 0){
				if(last2 % 2 == i % 2 && rle[i].first == rle[last2].first){
					bool bad = true;
					for(int j = last2 + 2; j < i; j += 2){
						if(rle[j].first != rle[i].first) bad = false;
					}
					if(bad) ans -= 1;
				}
			}
			last2 = i;
		}
	}
	cout << ans << '\n';
}