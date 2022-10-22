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
llint a[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		sort(a+1, a+n+1);
		
		if(a[n] < 0){
			llint ans = 1;
			for(int i = n; i >= n-4; i--) ans *= a[i];
			cout << ans << endl;
			continue;
		}
		
		vector<llint> pvec, nvec;
		for(int i = 1; i <= n; i++){
			if(a[i] >= 0) pvec.push_back(abs(a[i]));
			else nvec.push_back(abs(a[i]));
		}
		sort(pvec.rbegin(), pvec.rend());
		sort(nvec.rbegin(), nvec.rend());
		
		if(n == 5){
			cout << a[1]*a[2]*a[3]*a[4]*a[5] << endl;
			continue;
		}
		
		llint ans = 0;
		if(pvec.size() >= 5) ans = max(ans, pvec[0]*pvec[1]*pvec[2]*pvec[3]*pvec[4]);
		if(pvec.size() >= 3 && nvec.size() >= 2){
			ans = max(ans, pvec[0]*pvec[1]*pvec[2]*nvec[0]*nvec[1]);
		}
		if(pvec.size() >= 1 && nvec.size() >= 4){
			ans = max(ans, pvec[0]*nvec[0]*nvec[1]*nvec[2]*nvec[3]);
		}
		cout << ans << endl;
	}
	
	return 0;
}