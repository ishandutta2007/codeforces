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
typedef pair<ll, string> Q;

ll n;
vector<ll> vec[200005];
map<ll, vector<P> > mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	llint x, a;
	rep(i, 1, n){
		cin >> x;
		rep(j, 0, x-1){
			cin >> a;
			vec[i].push_back(a);
		}
		ll sum = 0;
		for(auto x : vec[i]) sum += x;
		rep(j, 0, x-1) mp[sum-vec[i][j]].push_back(P(i, j+1));
	}

	for(auto v : mp){
		vector<P> &vec = v.second;
		sort(vec.begin(), vec.end());
		if(vec.front().first != vec.back().first){
			cout << "YES" << endl;
			cout << vec.front().first << " " << vec.front().second << endl;
			cout << vec.back().first << " " << vec.back().second << endl;
			return 0;
		}
	}
	cout << "NO" << endl;

	return 0;
}