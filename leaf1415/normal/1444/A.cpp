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

llint T;
llint p, q;
bool prime[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	rep(i, 2, 1005){
		if(prime[i]) continue;
		for(int j = 2*i; j < 100005; j+=i) prime[j] = true;
	}
	
	cin >> T;
	while(T--){
		cin >> p >> q;
		
		if(p % q){
			cout << p << endl;
			continue;
		}
		
		map<llint, llint> mp;
		rep(i, 2, 100000){
			if(prime[i]) continue;
			while(q % i == 0){
				mp[i]++;
				q /= i;
			}
		}
		if(q > 1) mp[q]++;
		
		llint ans = 0;
		for(auto x : mp){
			llint t = p, cnt = 0;
			while(t % x.first == 0) t /= x.first, cnt++;
			t = p;
			rep(i, 1, cnt-x.second+1) t /= x.first;
			ans = max(ans, t);
		}
		cout << ans << endl;
	}
	
	return 0;
}