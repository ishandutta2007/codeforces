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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

llint n;
llint a[100005];
llint l[100005], r[100005];
bool used[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	
	rep(i, 1, n){
		if(!used[a[i]]) used[a[i]] = true, l[i] = 1;
	}
	
	rep(i, 1, 100000) used[i] = false;
	for(int i = n; i >= 1; i--){
		if(!used[a[i]]) used[a[i]] = true, r[i] = 1;
	}
	
	llint ans = 0, cnt = 0;
	rep(i, 1, n){
		ans += r[i]*cnt;
		cnt += l[i];
	}
	cout << ans << endl;
	
	return 0;
}