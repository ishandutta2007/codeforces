#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin >> s;
	int n = (int)s.size();
	int st = -1;
	int en = n;
	while(st + 1 < en){
		int mid = (st + en) / 2;
		bool works = false;
		int left0 = 0;
		for(char c : s) if(c == '0') left0++;
		int rem1 = 0;
		int l = 0;
		while(l < n && left0 > mid){
			if(s[l] == '0'){
				left0--;
			} else {
				rem1++;
			}
			l++;
		}
		if(left0 <= mid && rem1 <= mid) works = true;
		int r = n;
		while(l > 0){
			l--;
			if(s[l] == '0'){
				left0++;
			} else {
				rem1--;
			}
			while(r > l && left0 > mid){
				r--;
				if(s[r] == '0'){
					left0--;
				} else {
					rem1++;
				}
			}
			if(left0 <= mid && rem1 <= mid) works = true;
		}
		if(works){
			en = mid;
		} else {
			st = mid;
		}
	}
	cout << en << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}