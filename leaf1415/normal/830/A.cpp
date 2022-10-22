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

ll n, k, p;
ll a[1005], b[2005];

bool check(ll t)
{
	ll pos = 1;
	rep(i, 1, n){
		while(pos <= k && (abs(a[i]-b[pos]) + abs(b[pos] - p) > t)) pos++;
		if(pos > k) return false;
		pos++;
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k >> p;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, k) cin >> b[i];
	sort(a+1, a+n+1), sort(b+1, b+k+1);
	
	ll ub = 4e9, lb = -1, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	cout << ub << endl;
	
	return 0;
}