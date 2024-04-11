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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define pback push_back
#define inf 1e18
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

llint T;
llint n;
llint a[5005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		
		bool flag = false;
		rep(i, 1, n){
			if(a[i] != a[1]) flag = true;
		}
		if(!flag){
			cout << "NO" << endl;
			continue;
		}
		
		vector<P> ans; llint p;
		rep(i, 1, n){
			if(a[i] != a[1]) ans.pback(P(i, 1)), p = i;
		}
		rep(i, 2, n){
			if(a[i] == a[1]) ans.pback(P(i, p));
		}
		
		cout << "YES" << endl;
		for(auto x : ans) cout << x.first << " " << x.second << endl;
	}
	
	return 0;
}