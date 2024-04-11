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

llint n, x;
llint a[500005], sum[500005];
llint ub[500005], lmin[500005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	llint m = (n+1)/2;
	for(int i = 1; i <= m; i++) cin >> a[i];
	cin >> x;
	for(int i = m+1; i <= n; i++) a[i] = x;
	for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];
	
	if(sum[n] > 0){
		cout << n << endl;
		return 0;
	}
	/*if(x > 0){
		cout << -1 << endl;
		return 0;
	}*/
	
	//for(int i = 0; i <= n; i++) cout << sum[i] << " ";  cout << endl;
	
	bool flag = true;
	for(int i = 0; i <= m; i++){
		if(i+n/2 > n) continue;
		if(sum[i+n/2] <= sum[i]) flag = false;
	}
	if(flag){
		cout << n/2 << endl;
		return 0;
	}
	
	flag = true;
	for(int i = 0; i <= m; i++){
		if(i+m > n) continue;
		if(sum[i+m] <= sum[i]) flag = false;
	}
	if(flag){
		cout << m << endl;
		return 0;
	}
	
	for(int i = 0; i <= m; i++){
		llint b = sum[m+1+i];
		if(b-sum[i] <= 0) ub[i] = -inf;
		else{
			if(x) ub[i] = (b-sum[i]+(-x)-1)/(-x)-1;
			else ub[i] = inf;
		}
	}
	
	llint mn = inf;
	for(int i = 0; i <= m; i++){
		mn = min(mn, ub[i]);
		lmin[i] = mn;
	}
	//for(int i = 0; i <= m; i++) cout << ub[i] << " "; cout << endl;
	
	for(int i = 0; i < n-m; i++){
		if(lmin[n-m-1-i] >= i){
			cout << i+m+1 << endl;
			return 0;
		}
	}
	
	cout << -1 << endl;
	
	return 0;
}