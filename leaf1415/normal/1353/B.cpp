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
llint n, k;
llint a[35];
vector<llint> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> k;
		llint x;
		vec.clear();
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1;i <= n; i++){
			cin >> x;
			vec.push_back(x);
		}
		sort(vec.rbegin(), vec.rend());
		vec.resize(k);
		for(int i = 1; i <= n; i++) vec.push_back(a[i]);
		sort(vec.rbegin(), vec.rend());
		
		llint ans = 0;
		for(int i = 0; i < n; i++) ans += vec[i];
		cout << ans << endl;
	}
	
	return 0;
}