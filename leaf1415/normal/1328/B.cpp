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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)

using namespace std;

llint T;
llint n, k;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> k;
		
		string ans;
		for(int i = 1; i <= n; i++) ans += "a";
		llint p = n;
		for(int i = 1; i <= n; i++){
			if(k > i){
				k -= i;
			}
			else{
				p = i;
				break;
			}
		}
		ans[n-p-1] = 'b';
		ans[n-k] = 'b';
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}