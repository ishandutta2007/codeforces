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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint n;
string s;
vector<llint> vec[2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> s;
		
		vec[0].clear(), vec[1].clear();
		llint id = 0; vector<llint> ans;
		for(int i = 0; i < s.size(); i++){
			llint c = s[i]%2;
			if(vec[1-c].size() == 0) vec[1-c].push_back(++id);
			llint x = vec[1-c].back();
			ans.push_back(x);
			vec[1-c].pop_back();
			vec[c].push_back(x);
		}
		
		cout << id << endl;
		for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
	}
	
	return 0;
}