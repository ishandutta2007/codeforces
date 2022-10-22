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
#define mod 998244353
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)

using namespace std;

llint n, k;
llint p[200005];
vector<llint> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> p[i];
	
	llint ans = 0;
	for(int i = n-k+1; i <= n; i++) ans += i;
	cout << ans << " ";
	
	for(int i = 1; i <= n; i++){
		if(p[i] >= n-k+1) vec.push_back(i);
	}
	
	ans = 1;
	for(int i = 1; i < vec.size(); i++){
		ans *= vec[i]-vec[i-1];
		ans %= mod;
	}
	cout << ans << endl;
	
	return 0;
}