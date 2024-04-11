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

llint n, k;
llint a[100005];
llint cut[100005];
priority_queue<P> Q;

llint calc(llint a, llint b)
{
	llint l = a/b, u = a/b+1;
	return u * u * (a%b) + l * l * (b - a%b);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i], cut[i] = 1;
	
	llint ans = 0;
	for(int i = 1; i <= n; i++) ans += a[i]*a[i];
	
	if(n < k){
		for(int i = 1; i <= n; i++){
			Q.push(P(calc(a[i], cut[i]) - calc(a[i], cut[i]+1), i));
		}
	}
	
	
	for(int i = 0; i < k-n; i++){
		ans -= Q.top().first;
		llint x = Q.top().second;
		Q.pop();
		
		cut[x]++;
		if(cut[x] >= a[x]) continue;
		Q.push(P(calc(a[x], cut[x]) - calc(a[x], cut[x]+1), x));
	}
	cout << ans << endl;
	
	return 0;
}