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
	
	for(int i = 1; i <= n; i+=2){
		ans[i] = vec.back();
		vec.pop_back();
	}
	for(int i = 2; i <= n; i+=2){
		ans[i] = vec.back();
		vec.pop_back();
	}
	
	cout << (n-1)/2 << endl;
	for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
	
	return 0;
}