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
llint a[100005];
llint cnt[35];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 1; t <= T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		for(int i = 0; i < 35; i++) cnt[i] = 0;
		for(int i = 1; i <= n; i++){
			llint d = 0;
			for(llint x = a[i]; x; x/=2) d++;
			cnt[d]++;
		}
		llint ans = 0;
		for(int i = 0; i < 35; i++) ans += cnt[i] * (cnt[i]-1) / 2;
		cout << ans << endl;
	}
	
	return 0;
}