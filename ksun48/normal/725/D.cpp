#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	LL lb, lw;
	cin >> lb >> lw;
	n--;
	vector<pair<LL,LL> > a;
	for(int i = 0; i < n; i++){
		pair<LL,LL> b;
		cin >> b.first >> b.second;
		b.first *= -1;
		a.push_back(b);
	}
	sort(a.begin(), a.end());
	for(int i = 0; i < n; i++){
		a[i].first *= -1;
	}
	int ans = 1e8;
	multiset<LL> easy;
	int cur = 0;

	while(1){
		while(cur < n && a[cur].first > lb){
			easy.insert(a[cur].second + 1 - a[cur].first);
			cur++;
		}
		ans = min(ans,(int)easy.size() + 1);

		if(easy.size() == 0) break;
		LL b = *easy.begin();
		if(lb < b){
			break;
		}
		lb -= b;
		easy.erase(easy.begin());
	}
	cout << ans << endl;
}