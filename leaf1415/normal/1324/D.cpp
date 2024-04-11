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
#define llint long long

using namespace std;

llint n;
llint a[200005], b[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i], a[i] -= b[i];
	
	sort(a+1, a+n+1);
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		ans += max(0LL, n+1-max((llint)(upper_bound(a, a+n+1, -a[i]) - a), i+1LL));
	}
	cout << ans << endl;
	
	return 0;
}