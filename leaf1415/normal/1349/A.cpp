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

int n;
int a[100005], cnt[200005], mcnt[200005];
bool prime[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 2; i < 200005; i++){
		if(prime[i]) continue;
		for(int j = 2*i; j < 200005; j+=i) prime[j] = true;
	}
	
	for(int i = 1; i <= n; i++) cnt[a[i]]++;
	for(int i = 1; i <= 200000; i++){
		for(int j = i; j <= 200000; j+=i) mcnt[i] += cnt[j];
	}
	
	llint ans = 1;
	for(int i = 2; i <= 200000; i++){
		if(prime[i]) continue;
		llint mul = 1;
		while(mul * i <= 200000 && mcnt[mul * i] >= n-1) mul *= i;
		ans *= mul;
	}
	cout << ans << endl;
	
	return 0;
}