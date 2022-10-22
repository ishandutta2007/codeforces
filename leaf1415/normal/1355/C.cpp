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

llint a, b, c, d;
llint dif[1000005], sum[1000005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b >> c >> d;
	for(int i = a; i <= b; i++){
		llint l = i+b, r = i+c;
		dif[l]++, dif[r+1]--;
	}
	for(int i = 1; i < 1000005; i++) dif[i] += dif[i-1];
	
	for(int i = 1000003; i >= 0; i--) sum[i] = sum[i+1] + dif[i];
	
	llint ans = 0;
	for(int i = c; i <= d; i++) ans += sum[i+1];
	cout << ans << endl;
	
	return 0;
}