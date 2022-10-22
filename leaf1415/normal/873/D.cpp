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
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n, k;
ll p[100005], q[100005];
queue<P> Q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	if(k % 2 == 0){
		cout << -1 << endl;
		return 0;
	}
	rep(i, 0, n-1) p[i] = i;
	
	k--; Q.push(P(0, n));
	while(k > 0 && Q.size()){
		ll l = Q.front().first, r = Q.front().second;
		Q.pop();
		if(r-l <= 1) continue;
		
		ll m = (l+r)/2;
		rep(i, l, m-1) q[i] = p[r-(m-i)];
		rep(i, m, r-1) q[i] = p[l+i-m];
		rep(i, l, r-1) p[i] = q[i];
		Q.push(P(l, m)), Q.push(P(m, r));
		k -= 2;
	}
	if(k > 0){
		cout << -1 << endl;
		return 0;
	}
	rep(i, 0, n-1) cout << p[i]+1 << " "; cout << endl;
	
	return 0;
}