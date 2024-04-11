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
llint n, x;
llint a[100005], s[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> x;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) s[i] = (s[i-1] + a[i]) % x;
		
		if(s[0] != s[n]){
			cout << n << endl;
			continue;
		}
		llint l = -1, r = -1;
		for(int i = 1; i <= n; i++){
			if(s[i] != s[0]){
				l = i;
				break;
			}
		}
		for(int i = n; i >= 1; i--){
			if(s[i] != s[0]){
				r = i;
				break;
			}
		}
		if(l == -1){
			cout << -1 << endl;
			continue;
		}
		cout << max(n-l, r) << endl;
	}
	
	return 0;
}