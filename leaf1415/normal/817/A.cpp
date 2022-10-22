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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size()-1; (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << (x) << endl
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll sx, sy, tx, ty;
ll x, y;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> sx >> sy >> tx >> ty >> x >> y;
	
	if(abs(sx-tx) % x || abs(sy-ty) % y){
		cout << "NO" << endl;
		return 0;
	}
	if(abs(sx-tx)/x%2 == abs(sy-ty)/y%2) outl("YES");
	else outl("NO");
	
	return 0;
}