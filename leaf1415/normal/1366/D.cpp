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

llint n;
int a[500005];
int prime[10000005];
int ans[500005], ans2[500005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 2; i < 10000005; i++){
		if(prime[i]) continue;
		for(int j = 2*i; j < 10000005; j+=i) prime[j] = i;
	}
	
	for(int i = 1; i <= n; i++){
		vector<llint> vec;
		llint x = a[i];
		while(prime[x]){
			vec.push_back(prime[x]);
			x /= prime[x];
		}
		if(x > 1) vec.push_back(x);
		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
		//cout << a[i] << endl;
		//for(int j = 0; j < vec.size(); j++) cout << vec[j] << " "; cout<< endl;
		if(vec.size() <= 1) ans[i] = ans2[i] = -1;
		else{
			ans[i] = vec[0];
			llint mul = 1;
			for(int j = 1; j < vec.size(); j++) mul *= vec[j];
			ans2[i] = mul;
		}
	}
	for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
	for(int i = 1; i <= n; i++) cout << ans2[i] << " "; cout << endl;
	
	return 0;
}