#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	vector<vector<int> > parts;
	vector<int> cur;
	for(int x : a){
		if(!cur.empty() && cur.back() == x){
			parts.push_back(cur);
			cur = {};
		}
		cur.push_back(x);
	}
	parts.push_back(cur);
	map<int,int> freq;
	for(auto& v : parts){
		freq[v.front()]++;
		freq[v.back()]++;
	}
	int best = -1;
	int bestf = -1;
	for(auto p : freq){
		if(p.second >= bestf){
			bestf = p.second;
			best = p.first;
		}
	}
	int z = 0;
	for(int x : a){
		if(x == best){
			z++;
		} else {
			z--;
		}
	}
	if(z >= 2){
		cout << -1 << '\n';
		return;
	}
	int score = -(int)parts.size() - 1 + bestf;
	score = max(score, 0);
	score += (int)parts.size() - 1;
	cout << score << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}