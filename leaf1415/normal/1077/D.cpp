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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

llint n, k;
llint a[200005], c[200005];
vector<llint> ans;

bool check(llint x, bool flag = false)
{
	llint ret = 0;
	rep(i, 1, 200000){
		ret += c[i] / x;
		if(flag){
			rep(j, 1, c[i]/x){
				if(ans.size() < k) ans.push_back(i);
			}
		}
	}
	return ret >= k;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	rep(i, 1, n) cin >> a[i], c[a[i]]++;
	
	llint ub = n+1, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) lb = mid;
		else ub = mid;
	}
	check(lb, 1);
	for(auto x : ans) cout<< x << " "; cout << endl;
	
	return 0;
}