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
#define mod 998244353

using namespace std;
typedef pair<llint, llint> P;

llint n, Q;
string s;
llint mul[11][500005];
set<P> S;

llint getPrev(llint x)
{
	auto it = S.lower_bound(P(x, 0));
	it--;
	return it->first;
}
llint getCur(llint x)
{
	auto it = S.lower_bound(P(x, 0));
	return it->first;
}

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

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> Q;
	cin >> s;
	s = "0" + s + (char)('0'+10);
	
	for(int i = 0; i < 10; i++){
		mul[i][0] = i+1, mul[i][1] = (i+1)*2+(9-i);
		for(int j = 2; j <= n; j++) mul[i][j] = (mul[i][j-1]*2 + mul[i][j-2]*8) % mod;
	}
	mul[10][0] = 1, mul[10][1] = 2;
	for(int j = 2; j <= n; j++) mul[10][j] = (mul[10][j-1]*2 + mul[10][j-2]*8) % mod;
	
	for(int i = 0; i <= n+1; i++){
		if(s[i] != '1') S.insert(P(i, s[i]-'0'));
	}
	
	llint ans = 1;
	for(auto it = S.begin(); it != S.end(); it++){
		if(it->first == 0) continue;
		auto pre = it; pre--;
		llint len = it->first - pre->first - 1;
		ans *= mul[it->second][len], ans %= mod;
	}
	
	llint x, d;
	for(int i = 1; i <= Q; i++){
		cin >> x >> d;
		llint pre = getPrev(x), cur = getCur(x), len = cur-pre-1, digit = s[cur]-'0';
		ans *= modpow(mul[digit][len], mod-2), ans %= mod;
		if(s[x] != '1'){
			if(d != 1){
				ans *= mul[d][len], ans %= mod;
				S.erase(P(x, digit));
				S.insert(P(x, d));
			}
			else{
				S.erase(P(x, digit));
				cur = getCur(x), len = cur-pre-1, digit = s[cur]-'0';
				ans *= modpow(mul[digit][cur-x-1], mod-2), ans %= mod;
				ans *= mul[digit][len], ans %= mod;
			}
		}
		else{
			if(d != 1){
				ans *= mul[digit][cur-x-1], ans %= mod;
				ans *= mul[d][x-pre-1], ans %= mod;
				S.insert(P(x, d));
			}
			else ans *= mul[digit][len], ans %= mod;
		}
		s[x] = '0'+d;
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}