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
llint a[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	
	llint mx = 0, sum = 0;
	rep(i, 1, n) mx = max(mx, a[i]), sum += a[i];
	
	llint l = inf, r = -inf;
	rep(i, 1, n){
		if(a[i] == mx) l = min(l, i), r = max(r, i);
	}
	
	vector<llint> vec;
	rep(i, 1, n){
		if(l == r && i == l) continue;
		if(sum-a[i] == mx*2) vec.push_back(i);
	}
	if(l == r){
		sum -= a[l], mx = 0;
		rep(i, 1, n){
			if(i == l) continue;
			mx = max(mx, a[i]);
		}
		if(mx*2 == sum) vec.push_back(l);
	}
	
	cout << vec.size() << endl;
	for(auto x : vec) cout << x << " "; cout << endl;
	
	return 0;
}