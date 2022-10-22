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
#define outl(x) cout << (x) << endl

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n;
ll l[200005], r[200005];
ll dif[400005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> l[i] >> r[i];
	
	map<ll, ll> mp;
	rep(i, 1, n) mp[l[i]], mp[r[i]];
	ll id = 1;
	for(auto &p : mp) p.second = id++;
	rep(i, 1, n){
		l[i] = mp[l[i]], r[i] = mp[r[i]];
		dif[l[i]]++, dif[r[i]+1]--;
	}
	
	rep(i, 1, 400000){
		dif[i] += dif[i-1];
		if(dif[i] > 2){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	
	return 0;
}