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
llint h, w, a, b;
llint ans[55][55];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> h >> w >> a >> b;
		if(h*a != w*b){
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				ans[i][j] = 0;
			}
		}
		for(int i = 0; i < h; i++){
			for(int j = 0; j < a; j++){
				ans[i][(i*a+j)%w] = 1;
			}
		}
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				cout << ans[i][j];
			}
			cout << endl;
		}
	}
	
	return 0;
}