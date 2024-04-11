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
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)

using namespace std;

llint n;
llint b[200005], a[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	llint mx = 0;
	for(int i = 1; i <= n; i++){
		cin >> b[i];
		a[i] = mx+b[i];
		mx = max(mx, a[i]);
	}
	for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
	
	return 0;
}