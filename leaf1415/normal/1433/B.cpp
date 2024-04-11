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
llint a[55];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		
		llint l = inf, r = -inf, cnt = 0;
		rep(i, 1, n){
			if(a[i]) l = min(l, i), r = max(r, i), cnt++;
		}
		cout << r-l+1 - cnt << endl;
	}
	
	return 0;
}