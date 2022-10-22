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
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll T;
ll n, m;
ll a[100005];
ll r; double p;

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> m;
		rep(i, 1, n) cin >> a[i];
		
		ll pos = 0;
		for(int i = n; i >= 1; i--){
			if(a[i] != i){
				pos = i;
				break;
			}
		}
		if(pos == 0){
			printf("%.11f\n", 1.0);
			rep(i, 1, m) cin >> r >> p;
			continue;
		}
		double ans = 1;
		rep(i, 1, m){
			cin >> r >> p;
			if(r >= pos) ans *= 1-p;
		}
		ans = 1 - ans;
		printf("%.11f\n", ans);
	}
	
	return 0;
}