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
llint n, k;
llint ans[305][305];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> k;
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				ans[i][j] = 0;
			}
		}
		
		if(k % n == 0) cout << 0 << endl;
		else cout << 2 << endl;
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(k <= 0) goto end;
				ans[(i+j)%n][j] = 1;
				k--;
			}
		}
		end:;
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << ans[i][j];
			}
			cout << endl;
		}
	}
	
	return 0;
}