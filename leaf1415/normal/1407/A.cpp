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
llint a[1005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		llint cnt0 = 0, cnt1 = 0;
		for(int i = 1; i <= n; i++){
			if(a[i] == 0) cnt0++;
			else cnt1++;
		}
		
		vector<llint> ans;
		for(int i = 1; i <= n; i++){
			if(cnt0 >= n/2 && a[i] == 0) ans.push_back(i);
			if(cnt0 < n/2 && a[i] == 1) ans.push_back(i);
		}
		if(cnt0 < n/2 && ans.size() % 2) ans.pop_back();
		
		cout << ans.size() << endl;
		for(int i = 0; i < ans.size(); i++) cout << a[ans[i]] << " "; cout << endl;
	}
	
	return 0;
}