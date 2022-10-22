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

llint n;
llint a[100005], ans[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	vector<llint> vec;
	for(int i = 1; i <= n; i++) vec.push_back(a[i]);
	sort(vec.begin(), vec.end());
	
	llint mx = 0;
	for(int i = 1; i < vec.size(); i++){
		llint lnum = i - (lower_bound(vec.begin(), vec.end(), vec[i-1]) - vec.begin());
		llint rnum = vec.end() - upper_bound(vec.begin(), vec.end(), vec[i-1]);
		//cout << lnum << " " << rnum << endl;
		if(lnum+1 <= rnum && i+1 <= n-i) mx = i;
	}
	
	vector<llint> tmp, tmp2;
	for(int i = 0; i < mx; i++) tmp.push_back(vec[i]); reverse(tmp.begin(), tmp.end());
	for(int i = mx; i < vec.size(); i++) tmp2.push_back(vec[i]); reverse(tmp2.begin(), tmp2.end());
	
	vector<llint> ans; llint nx = 0;
	for(int i = 0; i < n; i++){
		if(nx == 0) ans.push_back(tmp2.back()), tmp2.pop_back(), nx = 1;
		else{
			if(tmp.size() && ans.back() > tmp.back() && tmp.size()) ans.push_back(tmp.back()), tmp.pop_back(), nx = 0;
			else ans.push_back(tmp2.back()), tmp2.pop_back(), nx = 1;
		}
	}
	
	llint cnt = 0;
	for(int i = 1; i < n-1; i++){
		if(ans[i-1] > ans[i] && ans[i] < ans[i+1]) cnt++;
	}
	cout << cnt << endl;
	for(int i = 0; i < n; i++) cout << ans[i] << " "; cout << endl;
	
	return 0;
}