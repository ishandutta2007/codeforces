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
llint a[200005], w[200005];
vector<llint> vec[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> k;
		for(int i = 1; i <= n; i++) cin >> a[i];
		sort(a+1, a+n+1);
		reverse(a+1, a+n+1);
		
		for(int i = 1; i <= k; i++){
			cin >> w[i];
			vec[i].clear();
		}
		sort(w+1, w+k+1);
		
		for(int i = 1; i <= k; i++) vec[i].push_back(a[i]), w[i]--;
		
		llint sum = k;
		for(int i = 1; i <= k; i++){
			for(int j = 1; j <= w[i]; j++) vec[i].push_back(a[sum+j]);
			sum += w[i];
		}
		
		llint ans = 0;
		for(int i = 1; i <= k; i++) ans += vec[i].front() + vec[i].back();
		
		cout << ans << endl;
	}
	
	return 0;
}