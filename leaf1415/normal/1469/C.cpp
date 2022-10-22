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
ll n, k;
ll h[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> k;
		rep(i, 1, n) cin >> h[i];
		
		ll l = -inf, r = inf;
		rep(i, 1, n){
			ll L = h[i], R = h[i]+k-1;
			if(i == 1 || i == n) R = h[i];
			chmax(L, l-k+1), chmin(R, r+k-1);
			l = L, r = R;
			if(l > r){
				cout << "NO" << endl;
				goto end;
			}
		}
		cout << "YES" << endl;
		end:;
	}
	
	return 0;
}