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
llint a[100005], cnt[100005];
llint b[100005], c[100005];

bool check(llint x)
{
	priority_queue<P> Q;
	for(int i = 1; i <= n; i++){
		if(cnt[i] > 0) Q.push(P(cnt[i], i));
		c[i] = cnt[i];
	}
	
	for(int i = 1; i <= n; i++){
		if(i-x >= 1){
			if(c[b[i-x]] > 0) Q.push(P(c[b[i-x]], b[i-x])); 
		}
		if(Q.size() == 0) return false;
		llint id = Q.top().second;
		Q.pop();
		b[i] = id, c[id]--;
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) cnt[i] = 0;
		for(int i = 1; i <= n; i++) cnt[a[i]]++;
		
		llint ub = n, lb = 0, mid;
		while(ub-lb>1){
			mid = (ub+lb)/2;
			if(check(mid)) lb = mid;
			else ub = mid;
		}
		cout << lb-1 << endl;
	}
	
	return 0;
}