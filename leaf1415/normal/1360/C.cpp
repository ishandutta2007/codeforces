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
llint a[55];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		sort(a+1, a+n+1);
		
		bool flag = false; llint cnt = 0;
		for(int i = 1; i < n; i++){
			if(a[i+1]-a[i] == 1) flag = true;
		}
		for(int i = 1; i<= n; i++){
			if(a[i]%2 == 0) cnt++;
		}
		if(flag || cnt%2==0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}