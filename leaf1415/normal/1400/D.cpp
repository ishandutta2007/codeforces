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

llint T;
llint n;
llint a[3005];
llint l[3005][3005], r[3005][3005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int z = 0; z < T; z++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		for(int j = 1; j <= n; j++) l[0][j] = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				l[i][j] = l[i-1][j];
			}
			l[i][a[i]]++;
		}
		
		for(int j = 1; j <= n; j++) l[n+1][j] = 0;
		for(int i = n; i >= 1; i--){
			for(int j = 1; j <= n; j++){
				r[i][j] = r[i+1][j];
			}
			r[i][a[i]]++;
		}
		
		llint ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i >= j) continue;
				ans += l[i-1][a[j]] * r[j+1][a[i]];
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}