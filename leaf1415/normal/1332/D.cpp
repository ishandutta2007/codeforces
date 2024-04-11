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

llint k;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> k;
	cout << 3 << " " << 3 << endl;
	llint N = (1<<18) - 1;
	cout << N << " " << k << " " << 0 << endl;
	cout << N-k << " " << N << " " << N << endl;
	cout << 0 << " " << N << " " << k << endl;
	
	return 0;
}