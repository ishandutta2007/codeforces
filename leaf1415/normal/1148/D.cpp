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
llint a[300005], b[300005];
vector<P> vec, vec2;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(llint i = 1; i <= n; i++){
		cin >> a[i] >> b[i];
		if(a[i] < b[i]) vec.push_back(P(b[i], i));
		else vec2.push_back(P(b[i], i));
	}
	sort(vec.rbegin(), vec.rend());
	sort(vec2.begin(), vec2.end());
	
	vector<P> ans;
	if((int)vec.size() > (int)vec2.size()) ans = vec;
	else ans = vec2;
	
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++) cout << ans[i].second << " "; cout << endl;
	
	return 0;
}