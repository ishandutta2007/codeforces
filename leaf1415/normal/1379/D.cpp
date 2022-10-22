#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

llint n, H, M, k;
llint h[100005], m[100005];
vector<P> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> H >> M >> k;
	rep(i, 1, n){
		cin >> h[i] >> m[i];
		m[i] %= M/2;
		vec.push_back(P(m[i], i));
		vec.push_back(P(m[i]+M/2, i));
	}
	sort(all(vec));
	
	llint min_val = inf, min_i;
	rep(i, 0, n-1){
		llint x = lower_bound(all(vec), P(vec[i].first+k, -inf)) - upper_bound(all(vec), P(vec[i].first, inf));
		if(min_val > x){
			min_i = i;
			min_val = x;
		}
	}
	llint t = vec[min_i].first;
	
	cout << min_val << " " << (t+k)%(M/2) << endl;
	
	vector<llint> ans;
	rep(i, 0, (int)vec.size()-1){
		if(vec[i].first > t && vec[i].first < t + k){
			ans.push_back(vec[i].second);
		}
	}
	sort(all(ans));
	
	for(auto x : ans) cout << x << " ";
	cout << endl;
	
	return 0;
}