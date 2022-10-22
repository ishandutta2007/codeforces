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
ll n, p, k;
string s;
ll x, y;
ll cnt[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> p >> k;
		cin >> s;
		cin >> x >> y;
		
		for(int i = (int)s.size()-1; i >= 0; i--){
			cnt[i] = 1 - s[i]%2;
			if(i+k < s.size()) cnt[i] += cnt[i+k];
		}
		ll ans = inf;
		rep(i, 0, n){
			if(i+p-1 >= s.size()) break;
			else chmin(ans, cnt[i+p-1]*x + i*y);
		}
		cout << ans << endl;
	}
	
	return 0;
}