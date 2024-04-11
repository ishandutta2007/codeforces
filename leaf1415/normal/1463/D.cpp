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

ll T;
ll n;
ll b[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) cin >> b[i];
		
		set<ll> S;
		rep(i, 1, 2*n) S.insert(i);
		rep(i, 1, n) S.erase(b[i]);
		
		ll r = 0;
		rep(i, 1, n){
			auto it = S.lower_bound(b[i]);
			if(it == S.end()) break;
			r++;
			S.erase(it);
		}
		
		rep(i, 1, 2*n) S.insert(i);
		rep(i, 1, n) S.erase(b[i]);
		
		ll l = n;
		for(int i = n; i >= 1; i--){
			auto it = S.lower_bound(b[i]);
			if(it == S.begin()) break;
			it--;
			l--;
			S.erase(it);
		}
		
		cout << r-l+1 << endl;
	}
	
	return 0;
}