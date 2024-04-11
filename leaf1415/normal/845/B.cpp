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

string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	rep(i, 0, 5) s[i] -= '0';
	
	ll ans = inf;
	rep(i, 0, 999){
		ll a[] = {i/100, i/10%10, i%10};
		rep(j, 0, 999){
			ll b[] = {j/100, j/10%10, j%10};
			
			if(a[0]+a[1]+a[2] != b[0]+b[1]+b[2]) continue;
			ll cnt = 0;
			if(a[0] != s[0]) cnt++;
			if(a[1] != s[1]) cnt++;
			if(a[2] != s[2]) cnt++;
			if(b[0] != s[3]) cnt++;
			if(b[1] != s[4]) cnt++;
			if(b[2] != s[5]) cnt++;
			chmin(ans, cnt);
		}
	}
	cout << ans << endl;
	
	return 0;
}