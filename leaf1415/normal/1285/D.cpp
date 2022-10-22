#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#define llint long long
#define inf 1e18

using namespace std;

llint n;
llint a[100005];

llint dfs(llint l, llint r, llint b)
{
	llint p = -1, ret = 0;
	for(int i = l; i < r; i++){
		if(((a[i]>>b) & 1LL) != ((a[i+1]>>b) & 1LL)){
			p = i;
			break;
		}
	}
	if(p != -1) ret |= 1LL<<b;
	if(b == 0) return ret;
	
	if(p == -1) ret += dfs(l, r, b-1);
	else ret += min(dfs(l, p, b-1), dfs(p+1, r, b-1));
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	
	cout << dfs(1, n, 30) << endl;
	
	return 0;
}