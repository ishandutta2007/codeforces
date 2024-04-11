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
llint a[5005], s[5005];

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> k;
	rep(i, 1, n) cin >> a[i], s[i] = s[i-1] + a[i];
	
	double ans = 0;
	rep(l, 1, n){
		rep(r, 1, n){
			if(r-l+1 < k) continue;
			chmax(ans, (double)(s[r]-s[l-1])/(r-l+1));
		}
		
	}
	printf("%.11f\n", ans);
	
	return 0;
}