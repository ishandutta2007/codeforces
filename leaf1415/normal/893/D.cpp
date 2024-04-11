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

ll n, d;
ll a[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> d;
	rep(i, 1, n) cin >> a[i];
	
	ll ub = 0, lb = 0, ans = 0;
	rep(i, 1, n){
		if(a[i]) ub += a[i], lb += a[i], chmin(ub, d);
		else{
			lb = chmax(lb, 0LL);
			if(ub < 0) ans++, ub = d;
		}
		if(ub < lb){
			cout << -1 << endl;
			return 0;
		}
	}
	cout << ans << endl;
	
	return 0;
}