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
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

string s;
vector<ll> vec[26];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	rep(i, 0, 25) vec[i].push_back(-1);
	rep(i, 0, (int)s.size()-1) vec[s[i]-'a'].push_back(i);
	rep(i, 0, 25) vec[i].push_back((int)s.size());

	ll ans = inf;
	rep(i, 0, 25){
		ll tmp = 0;
		rep(j, 1, (int)vec[i].size()-1) chmax(tmp, vec[i][j] - vec[i][j-1]);
		chmin(ans, tmp);
	}
	cout << ans << endl;

	return 0;
}