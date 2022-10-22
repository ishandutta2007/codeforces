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
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll l, r, x, y, k;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> l >> r >> x >> y >> k;
	l = (l+k-1)/k*k, r = r / k * k;
	
	if(l > r || x*k > r || y*k < l) cout << "NO" << endl;
	else cout << "YES"<< endl;
	
	return 0;
}