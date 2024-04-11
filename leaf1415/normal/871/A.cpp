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

ll Q;
ll n;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	while(Q--){
		cin >> n;
		ll ans = 0;
		if(n % 2){
			if(n < 9){
				cout << -1 << "\n";
				continue;
			}
			n -= 9, ans++;
		}
		if(n > 0 && n < 4){
			cout << -1 << "\n";
			continue;
		}
		if(n/2%2) n -= 6, ans++;
		ans += n/4;
		cout << ans << "\n";
	}
	
	return 0;
}