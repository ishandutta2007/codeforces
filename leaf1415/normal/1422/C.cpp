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
llint beki[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	n = s.size();
	reverse(s.begin(), s.end());
	
	beki[0] = 1;
	for(int i = 1; i <= n; i++) beki[i] = beki[i-1] * 10 % mod;
	
	llint ans = 0, sum = 0;
	for(int i = 0; i < n; i++){
		llint x = (n-i-1)*(n-i)/2%mod * beki[i] % mod;
		x += sum, x %= mod;
		ans += (s[i]-'0') * x % mod, ans %= mod;
		sum += beki[i] * (i+1) % mod, sum %= mod;
	}
	cout << ans << endl;
	
	return 0;
}