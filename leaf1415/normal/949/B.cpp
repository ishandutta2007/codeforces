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
#define chmin(x, y) (x) =) min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n, Q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> Q;
	ll x;
	rep(i, 1, Q){
		cin >> x;
		x = 2*n-x;
		while(x % 2 == 0) x /= 2;
		x = (x-1) / 2;
		cout << n - x << "\n";
	}
	flush(cout);

	return 0;
}