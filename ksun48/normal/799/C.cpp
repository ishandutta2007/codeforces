#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, c, d;
	cin >> n >> c >> d;
	vector<pair<int,int> > coins;
	vector<pair<int,int> > diams;

	vector<int> maxc, maxd;

	for(int i = 0; i < n; i++){
		int a, b;
		string dd;
		cin >> a >> b >> dd;
		if(dd[0] == 'C'){
			coins.push_back(make_pair(b,a));
		} else {
			diams.push_back(make_pair(b,a));
		}
	}
	sort(coins.begin(), coins.end());
	sort(diams.begin(), diams.end());
	int r = -1e7;
	maxc.push_back(r);
	for(int i = 0; i < coins.size(); i++){
		r = max(r,coins[i].second);
		maxc.push_back(r);
	}
	r = -1e7;
	maxd.push_back(r);
	for(int i = 0; i < diams.size(); i++){
		r = max(r,diams[i].second);
		maxd.push_back(r);
	}
	int ans = 0;
	int b1 = 0;
	int b2 = 0;
	while(b1 < coins.size() && coins[b1].first <= c){
		b1++;
	}
	while(b2 < diams.size() && diams[b2].first <= d){
		b2++;
	}
	ans = max(ans,maxc[b1]+maxd[b2]);
	b1 = 0;
	b2 = 0;
	for(int f = coins.size(); f--; f >= 0){
		while(b1 < coins.size() && (coins[b1].first + coins[f].first <= c)){
			b1++;
		}
		ans = max(ans, maxc[min(f,b1)]+coins[f].second);
	}
	for(int f = diams.size(); f--; f >= 0){
		while(b2 < diams.size() && (diams[b2].first + diams[f].first <= d)){
			b2++;
		}
		ans = max(ans, maxd[min(f,b2)]+diams[f].second);
	}
	cout << ans << endl;
}