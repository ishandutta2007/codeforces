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

ll n;
string s;
map<ll, ll> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s;
	s = "#" + s;
	
	ll h = 0;
	mp[0] = 0;
	rep(i, 1, n){
		if(s[i] == '0') h++;
		else h--;
		mp[h] = i;
	}
	
	ll ans = mp[0];
	h = 0;
	rep(i, 1, n){
		if(s[i] == '0') h++;
		else h--;
		chmax(ans, mp[h] - i);
	}
	cout << ans << endl;
	
	return 0;
}