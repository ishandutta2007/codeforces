#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<pair<int,int> > locs;
	for(int i = 0; i < n; i++) cin >> a[i];
	int cur = 0;
	int last3 = -1;
	for(int i = 0; i < n; i++){
		if(a[i] == 3){
			if(last3 != -1){
				locs.push_back({cur, last3});
				locs.push_back({cur, i});
				cur++;
			}
			last3 = i;
			a[i] = 0;
		}
	}
	if(last3 != -1){
		int done = 0;
		for(int i = last3+1; i < n; i++){
			if(a[i] == 2){
				locs.push_back({cur, last3});
				locs.push_back({cur, i});
				cur++;
				done = 1;
				break;
			}
		}
		if(!done){
			for(int i = last3+1; i < n; i++){
				if(a[i] == 1){
					locs.push_back({cur, last3});
					locs.push_back({cur, i});
					cur++;
					locs.push_back({cur, i});
					cur++;
					done = 1;
					a[i] = 0;
					break;
				}
			}
		}
		if(!done){
			cout << -1 << '\n';
			return 0;
		}
	}
	int p1 = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == 2){
			while(p1 < n && (p1 < i || a[p1] != 1)) p1++;
			if(p1 == n){
				cout << -1 << '\n';
				return 0;
			}
			locs.push_back({cur, i});
			locs.push_back({cur, p1});
			cur++;
			a[i] = a[p1] = 0;
		}
	}
	for(int i = 0; i < n; i++){
		if(a[i] == 1){
			locs.push_back({cur, i});
			cur++;
			a[i] = 0;
		}
	}
	cout << locs.size() << '\n';
	for(pair<int,int> p : locs){
		cout << p.first + 1 << ' ' << p.second + 1 << '\n';
	}
}