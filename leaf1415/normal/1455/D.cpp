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
ll n, x;
ll a[505];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> x;
		rep(i, 1, n) cin >> a[i];
		
		ll ans = 0;
		while(1){
			bool flag = true;
			rep(i, 1, n-1){
				flag &= (a[i] <= a[i+1]);
			}
			if(flag) break;
			
			ans++;
			flag = false;
			rep(i, 1, n){
				if(a[i] > x){
					flag = true;
					swap(x, a[i]);
					break;
				}
			}
			if(!flag){
				ans = inf;
				break;
			}
		}
		if(ans > inf/2) ans = -1;
		cout << ans << endl;
	}
	
	return 0;
}