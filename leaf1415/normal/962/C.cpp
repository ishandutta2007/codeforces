#include <iostream>
#include <vector>
#include <algorithm>
#define llint long long
#define inf 1000000000

using namespace std;

llint n;
vector<llint> vec;

llint keta(llint x)
{
	llint ret = 0;
	for(; x; x/=10) ret++;
	return ret;
}

llint dfs(llint x)
{
	if(x == 0) return inf;
	auto p = lower_bound(vec.begin(), vec.end(), x);
	if(p != vec.end() && *p == x) return 0;
	
	llint k = keta(x), m = 1;
	llint ret = inf;
	for(int i = 0; i < k; i++, m *= 10){
		llint y = x%m + x/(m*10)*m;
		if(keta(y) < k-1) continue;
		ret = min(ret, dfs(y) + 1);
	}
	return ret;
}

int main(void)
{
	for(llint i = 1; i*i <= 2000000005; i++) vec.push_back(i*i);
	cin >> n;
	
	llint ans = dfs(n);
	if(ans >= inf) cout << -1 << endl;
	else cout << ans << endl;
	
	return 0;
}