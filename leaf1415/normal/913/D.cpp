#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int n, T;
vector< pair<pair<int, int>, int> > vec;

bool check(int x)
{
	int cnt = 0, remT = T;
	for(int i = 0; i < vec.size(); i++){
		if(vec[i].first.second < x) continue;
		if(vec[i].first.first > remT) break;
		cnt++;
		remT -= vec[i].first.first;
	}
	return cnt >= x;
}

int main(void)
{
	cin >> n >> T;
	int a, t;
	for(int i = 0; i < n; i++){
		cin >> a >> t;
		vec.push_back( make_pair(make_pair(t, a), i+1) );
	}
	sort(vec.begin(), vec.end());
	
	int lb = -1, ub = 1000000005, mid;
	while(ub - lb > 1){
		mid = (lb + ub) / 2;
		if(check(mid)) lb = mid;
		else ub = mid;
	}
	
	int ans = lb;
	int cnt = 0, remT = T;
	vector<int> ans_p;
	for(int i = 0; i < vec.size(); i++){
		if(vec[i].first.second < ans) continue;
		if(vec[i].first.first > remT) break;
		if(cnt >= ans) break;
		cnt++;
		remT -= vec[i].first.first;
		ans_p.push_back(vec[i].second);
	}
	
	cout << ans << endl;
	cout << ans_p.size() << endl;
	for(int i = 0; i < ans_p.size(); i++){
		cout << ans_p[i];
		if(i != ans_p.size()-1) cout << " ";
	}
	cout << endl;
	return 0;
}