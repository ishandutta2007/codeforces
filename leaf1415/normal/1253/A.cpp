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
llint a[100005], b[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) cin >> b[i];
		
		llint l = inf, r = -inf;
		for(llint i = 1; i <= n; i++){
			if(a[i] != b[i]){
				l = min(l, i);
				r = max(r, i);
			}
		}
		
		if(l > n){
			cout << "YES" << endl;
			continue;
		}
		
		for(int i = l; i <= r; i++){
			if(a[i] > b[i] || b[l]-a[l] != b[i]-a[i]){
				cout << "NO" << endl;
				goto end;
			}
		}
		cout << "YES" << endl;
		end:;
	}
	
	return 0;
}