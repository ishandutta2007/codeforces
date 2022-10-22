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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define mod 998244353

using namespace std;

llint n;
llint ans[200005];
llint beki[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	beki[0] = 1;
	for(int i = 1; i < 200005; i++) beki[i] = beki[i-1] * 10, beki[i] %= mod;
	
	cin >> n;
	for(int i = 1; i <= n-1; i++){
		llint sum = 0;
		if(i <= n-2){
			sum = beki[n-(i+2)] * 9 * 9 * 10 % mod;
			sum *= (n-1)-i, sum %= mod;
		}
		sum += beki[n-(i+1)] * 18 * 10% mod, sum %= mod;
		ans[i] = sum;
	}
	ans[n] = 10;
	
	for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
	
	return 0;
}