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

llint T;
llint n, m;
P p[100005];
llint sum[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> m;
		rep(i, 1, m) cin >> p[i].first >> p[i].second;
		sort(p+1, p+m+1);
		
		sum[m+1] = 0;
		for(int i = m; i >= 1; i--) sum[i] = sum[i+1] + p[i].first;
		
		llint ans = 0;
		rep(i, 1, m){
			llint tmp = p[i].first, rem = n-1;
			llint pos = lower_bound(p+1, p+m+1, P(p[i].second, -inf)) - p;
			llint l = m+1 - rem;
			if(l <= i) l--;
			l = max(l, 1LL);
			
			llint x = max(l, pos);
			tmp += sum[x], rem -= m-x+1;
			if(x <= i) tmp -= p[i].first, rem++;
			
			tmp += rem * p[i].second;
			ans = max(ans, tmp);
		}
		cout << ans << endl;
	}
	
	return 0;
}