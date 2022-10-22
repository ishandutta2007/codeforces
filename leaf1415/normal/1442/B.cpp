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
#define mod 998244353

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

llint T;
llint n, k;
llint a[200005], b[200005];
bool used[200005];
list<llint> ls;
list<llint>::iterator p[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> k;
		rep(i, 1, n) used[i] = false;
		
		ls.clear();
		ls.push_back(0);
		rep(i, 1, n) cin >> a[i], ls.push_back(a[i]);
		rep(i, 1, k) cin >> b[i], used[b[i]] = true;
		ls.push_back(0);
		
		for(auto it = ls.begin(); it != ls.end(); it++) p[*it] = it;
		
		llint ans = 1;
		rep(i, 1, k){
			auto it = p[b[i]];
			auto pre = it; pre--;
			auto suc = it; suc++;
			
			llint mul = 0;
			if(*pre != 0 && !used[*pre]) mul++;
			if(*suc != 0 && !used[*suc]) mul++;
			ans *= mul, ans %= mod;
			ls.erase(it);
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}