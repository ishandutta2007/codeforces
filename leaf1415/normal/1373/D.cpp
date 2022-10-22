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
llint a[200005];
llint b[200005], s[200005], m[200005];

llint calc(llint a[], llint n)
{
	//for(int i = 1; i <= n; i++) cout << b[i] << " "; cout << endl;
	
	for(int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];
	for(int i = 1; i <= n; i++) m[i] = min(m[i-1], s[i]);
	
	llint ret = -inf;
	for(int i = 1; i <= n; i++) ret = max(ret, s[i]-m[i-1]);
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		if(n == 1){
			cout << a[1] << endl;
			continue;
		}
		if(n == 2){
			cout << max(a[1], a[2]) << endl;
			continue;
		}
		
		llint sum = 0;
		for(int i = 1; i <= n; i+=2) sum += a[i];
		
		llint ans = 0;
		for(int i = 1; i <= n/2; i++) b[i] = a[2*i] - a[2*i-1];
		ans = max(ans, calc(b, n/2));
		
		for(int i = 1; i <= n-1; i++) a[i] = a[i+1];
		n--;
		for(int i = 1; i <= n/2; i++) b[i] = a[2*i-1] - a[2*i];
		ans = max(ans, calc(b, n/2));
		
		ans += sum;
		cout << ans << endl;
	}
	
	return 0;
}