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

llint n;
string s;
llint acnt[200005], ccnt[200005];
llint lcnt[200005], rcnt[200005];

llint modpow(llint a, llint n)
{
	if(n < 0) return 0;
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	cin >> s;
	s = "#" + s;
	
	for(int i = 1; i <= n; i++){
		acnt[i] = acnt[i-1], lcnt[i] = lcnt[i-1];
		if(s[i] == 'a') acnt[i]++;
		if(s[i] == '?') lcnt[i]++;
	}
	for(int i = n; i >= 1; i--){
		ccnt[i] = ccnt[i+1], rcnt[i] = rcnt[i+1];
		if(s[i] == 'c') ccnt[i]++;
		if(s[i] == '?') rcnt[i]++;
	}
	llint qcnt = lcnt[n];
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		if(s[i] == 'b' || s[i] == '?'){
			if(s[i] == '?') qcnt--;
			llint tmp = acnt[i-1]*ccnt[i+1]%mod*modpow(3, qcnt)%mod;
			tmp += acnt[i-1]*rcnt[i+1]%mod*modpow(3, qcnt-1)%mod, tmp %= mod;
			tmp += lcnt[i-1]*ccnt[i+1]%mod*modpow(3, qcnt-1)%mod, tmp %= mod;
			tmp += lcnt[i-1]*rcnt[i+1]%mod*modpow(3, qcnt-2)%mod, tmp %= mod;
			ans += tmp, ans %= mod;
			if(s[i] == '?') qcnt++;
		}
	}
	cout << ans << endl;
	
	return 0;
}