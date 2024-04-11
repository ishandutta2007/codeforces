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
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;

llint modpow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
	}
}


llint T;
llint n, p;
llint k[1000005];
stack<P> stk;

void spush(llint k)
{
	if(stk.size() == 0){
		stk.push(P(k, 1));
		return;
	}
	if(stk.top().first == k) stk.top().second++;
	else stk.push(P(k, 1));
	
	if(stk.top().second == p){
		llint t = stk.top().first;
		stk.pop();
		spush(t+1);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> p;
		for(int i = 1; i <= n; i++) cin >> k[i];
		sort(k+1, k+n+1);
		reverse(k+1, k+n+1);
		
		if(p == 1){
			cout << n%2 << "\n";
			continue;
		}
		
		while(stk.size()) stk.pop();
		llint obj = -1;
		for(int i = 1; i <= n; i++){
			if(obj == -1){
				obj = k[i];
				continue;
			}
			spush(k[i]);
			if(stk.top().first == obj){
				stk.pop();
				obj = -1;
			}
		}
		if(obj == -1){
			cout << 0 << "\n";
			continue;
		}
		llint ans = modpow(p, obj);
		while(stk.size()){
			ans += mod - modpow(p, stk.top().first) * stk.top().second % mod;
			ans %= mod;
			stk.pop();
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}