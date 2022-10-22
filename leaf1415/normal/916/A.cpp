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

ll x;
ll h, m;

bool check(ll m)
{
	if(m < 0) m += 24*60;
	ll h = m / 60;
	m %= 60;
	
	if(h % 10 == 7) return true;
	if(m % 10 == 7) return true;
	return false;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> x >> h >> m;
	m = h*60+m;
	
	ll ans = 0;
	while(!check(m)) m -= x, ans++;
	cout << ans << endl;
	
	return 0;
}