#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k, p;
	cin >> n >> k >> p;
	vector<vector<int> > s(p);
	vector<vector<int> > t(k-p);
	vector<int> odds;
	vector<int> evens;
	int r = 0;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		if(a % 2 == 1){
			if(r < k-p){
				t[r].push_back(a);
				r++;
			} else {
				odds.push_back(a);
			}
		} else {
			evens.push_back(a);
		}
	}
	if(odds.size() & 1 || r < k-p){
		cout << "NO" << '\n';
		return 0;
	}
	vector<vector<int> > z;
	for(int a : evens) z.push_back({a});
	for(int i = 0; i < (int)odds.size(); i += 2){
		z.push_back({odds[i], odds[i+1]});
	}
	int f = 0;
	for(vector<int> x : z){
		if(f < p){
			for(int a : x) s[f].push_back(a);
			f++;
		} else if(r < k-p){
			for(int a : x) t[r].push_back(a);
			r++;
		} else if(s.size() > 0){
			for(int a : x) s[0].push_back(a);
		} else {
			for(int a : x) t[0].push_back(a);
		}
	}
	if(f < p || r < k-p){
		cout << "NO" << '\n';
		return 0;
	}
	cout << "YES" << '\n';
	for(vector<int> q : s){
		cout << q.size();
		for(int a : q){
			cout << ' ' << a;
		}
		cout << '\n';
	}
	for(vector<int> q : t){
		cout << q.size();
		for(int a : q){
			cout << ' ' << a;
		}
		cout << '\n';
	}
}