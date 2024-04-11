#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n, k;
vector<P> vec;
priority_queue<llint, vector<llint>, greater<llint> > Q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	llint t, b;
	for(int i = 1; i <= n; i++){
		cin >> t >> b;
		vec.push_back(make_pair(b, t));
	}
	sort(vec.rbegin(), vec.rend());
	
	llint mn = 1e18, ans = 0, sum = 0;
	for(int i = 0; i < vec.size(); i++){
		mn = vec[i].first;
		Q.push(vec[i].second);
		sum += vec[i].second;
		if(Q.size() > k){
			sum -= Q.top();
			Q.pop();
		}
		ans = max(ans, sum*mn);
	}
	cout << ans << endl;
	
	return 0;
}