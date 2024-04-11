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
llint a[1005], ans[1005], p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) ans[i] = 0;
		
		llint id = 1;
		for(int i = 0; i < 11; i++){
			bool flag = false;
			for(int j = 1; j <= n; j++){
				if(ans[j]) continue;
				if(a[j] % p[i] == 0){
					flag = true;
					ans[j] = id;
				}
			}
			if(flag) id++;
		}
		cout << id-1 << endl;
		for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
	}
	
	return 0;
}