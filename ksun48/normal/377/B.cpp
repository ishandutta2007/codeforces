#include<iostream>
#include<utility>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;

int main(){
	LL n, m, s;
	cin >> n >> m >> s;
	pair<LL,LL> a[m];
	pair<LL,pair<LL,LL> > student[n];
	for(LL i = 0; i < m; i++){
		cin >> a[i].first;
		a[i].first = -a[i].first;
		a[i].second = i;
	}
	sort(a, a+m);
	for(LL i = 0; i < m; i++){
		a[i].first = -a[i].first;
	}
	for(LL i = 0; i < n; i++){
		cin >> student[i].first;
		student[i].first = -student[i].first;
		student[i].second.second = i+1;
	}
	for(LL i = 0; i < n; i++) cin >> student[i].second.first;
	sort(student, student+n);
	for(LL i = 0; i < n; i++){
		student[i].first = -student[i].first;
	}
	LL maxguy = 0;
	for(LL i = 0; i < n; i++){
		if(student[i].second.first <= s){
			maxguy = max(maxguy, student[i].first);
		}
	}
	for(LL i = 0; i < m; i++){
		if(a[i].first > maxguy){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	LL start = m;
	LL end = 0;
	while(start > end+1){
		LL k = (start+end)/2;
		multiset<LL> passes;
		LL cur = 0;
		LL cost = 0;
		for(LL i = 0; i < m; i+=k){
			while(cur < n && student[cur].first >= a[i].first){
				passes.insert(student[cur].second.first);
				cur++;
			}
			if(passes.size() == 0){
				cost = -1;
				break;
			}
			cost += *passes.begin();
			passes.erase(passes.begin());
		}
		if(cost == -1 || cost > s){
			end = k;
		} else {
			start = k;
		}
	}
	LL bughelp[m];
	LL k = start;
	//cout << k << endl;
	multiset<pair<LL,LL> > passes;
	LL cur = 0;
	for(LL i = 0; i < m; i+=k){
		while(cur < n && student[cur].first >= a[i].first){
			passes.insert(student[cur].second);
			cur++;
		}
		for(LL j = 0; i+j < m && j < k; j++){
			bughelp[a[i+j].second] = (*passes.begin()).second;
		}
		passes.erase(passes.begin());
	}
	for(LL i = 0; i < m; i++){
		cout << bughelp [i] << " ";
	}
	cout << endl;
}