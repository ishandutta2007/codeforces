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
ll a[200005], c[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) c[i] = 0;
		rep(i, 1, n){
			cin >> a[i];
			if(c[a[i]] == -1) continue;
			if(c[a[i]] == 0) c[a[i]] = i;
			else c[a[i]] = -1;
		}
		
		ll ans = -1;
		rep(i, 1, n){
			if(c[i] >= 1){
				ans = c[i];
				break;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}