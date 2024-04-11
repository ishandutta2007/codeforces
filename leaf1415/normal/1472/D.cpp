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
ll a[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) cin >> a[i], a[i] *= 2;
		
		vector<ll> vec;
		ll ans = 0; 
		rep(i, 1, n){
			vec.push_back(a[i]/2);
			if(a[i]/2 % 2 == 0) ans += a[i]/2;
			else ans -= a[i]/2;
		}
		
		sort(all(vec)), reverse(all(vec));
		rep(i, 0, (int)vec.size()-1){
			if(i % 2 == 0) ans += vec[i];
			else ans -= vec[i];
		}
		if(ans > 0)  cout << "Alice" << endl;
		else if(ans < 0) cout << "Bob" << endl;
		else cout << "Tie" << endl;
	}
	
	return 0;
}