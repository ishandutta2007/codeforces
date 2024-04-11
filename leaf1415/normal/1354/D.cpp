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
#define PI 3.141592653589793238

using namespace std;
typedef pair<llint, llint> P;

llint n, Q;
llint k[1000005];
llint cnt[1000005], sum[1000005];

bool check(llint x)
{
	llint ret = sum[x];
	for(int i = 1; i <= Q; i++){
		if(k[i] >= 0){
			if(k[i] <= x) ret++;
		}
		else{
			if(-k[i] <= ret) ret--;
		}
	}
	return ret > 0;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> Q;
	llint a;
	for(int i = 1; i <= n; i++){
		cin >> a;
		cnt[a]++;
	}
	for(int i = 1; i <= 1000000; i++) sum[i] = sum[i-1] + cnt[i];
	
	for(int i = 1; i <= Q; i++) cin >> k[i];
	
	llint ub = 1000001, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	if(ub > 1000000) ub = 0;
	cout << ub << endl;
	
	return 0;
}