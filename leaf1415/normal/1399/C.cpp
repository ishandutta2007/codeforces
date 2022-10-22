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
llint w[55];
llint cnt[105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> w[i];
		
		for(int i = 0; i <= 2*n; i++) cnt[i] = 0;
		for(int i = 1; i <= n; i++) cnt[w[i]]++;
		
		llint ans = 0;
		for(llint i = 2; i <= 2*n; i++){
			llint tmp = 0;
			for(int j = 1; j <= i/2; j++){
				if(2*j == i) tmp += cnt[j]/2;
				else tmp += min(cnt[j], cnt[i-j]);
			}
			ans = max(ans, tmp);
		}
		cout << ans << endl;
	}
	
	return 0;
}