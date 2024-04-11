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

llint T;
llint n;
set<llint> S;

llint gcd(llint a, llint b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}
llint lcm(llint a, llint b)
{
	return a/gcd(a, b)*b;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 1; t <= T; t++){
		cin >> n;
		S.clear();
		for(llint i = 1; i*i <= n; i++){
			if(n % i == 0) S.insert(i), S.insert(n/i);
		}
		llint ans = inf, ans_i;
		for(auto it = S.begin(); it != S.end(); it++){
			if(*it == n) continue;
			llint l = lcm(*it, n-*it);
			if(ans > l){
				ans = l;
				ans_i = *it;
			}
		}
		cout << ans_i << " " << n-ans_i << endl;
	}
	
	return 0;
}