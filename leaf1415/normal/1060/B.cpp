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

llint n;

llint calc(llint x)
{
	llint k = 0;
	for(llint t = x; t; t/=10) k += t%10;
	return k;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	llint k = 0;
	for(llint t = n; t; t/=10) k++;
	
	llint K = 1 << k, ans = 0;
	rep(i, 0, K-1){
		llint sum = 0;
		rep(j, 0, k-1){
			sum *= 10;
			if(i & (1<<j)) sum += 9;
		}
		if(sum > n) continue;
		ans = max(ans, calc(sum) + calc(n-sum));
	}
	cout << ans << endl;
	
	return 0;
}