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

llint n, m;
llint x, k, y;
llint a[200005], b[200005];
bool used[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	cin >> x >> k >> y;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) cin >> b[i];
	
	llint p = 1;
	for(int i = 1; i <= n; i++){
		if(a[i] == b[p]){
			used[i] = true;
			p++;
		}
	}
	used[n+1] = true;
	if(p <= m){
		cout << -1 << endl;
		return 0;
	}
	
	
	llint l = 0, mx = 0, ans = 0;
	for(int i = 1; i <= n+1; i++){
		if(!used[i]) mx = max(mx, a[i]);
		else{
			llint r = i, len = r-l-1;
			//cout << l << " " << r << endl;
			if(len > 0){
				if(max(a[l], a[r]) > mx){
					ans += len/k*min(y*k, x) + len%k*y;
				}
				else{
					if(len < k){
						cout << -1 << endl;
						return 0;
					}
					if(y*k <= x) ans += (len-k)*y + x;
					else ans += len%k*y + len/k*x;
				}
			}
			mx = 0, l = i;
		}
	}
	cout << ans << endl;
	
	return 0;
}