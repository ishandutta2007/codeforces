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

ll n, k;
map<ll, ll> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	
	ll sum = 0;
	rep(i, 0, 60){
		if(n & (1LL<<i)) mp[i]++, sum++;
	}
	if(sum > k){
		cout << "No" << endl;
		return 0;
	}
	
	ll p = 60;
	while(sum < k){
		while(mp[p] == 0) p--;
		if(mp[p] <= k - sum){
			mp[p-1] += mp[p]*2, sum += mp[p], mp[p] = 0;
		}
		else break;
	}
	while(sum < k){
		auto it = mp.begin();
		it->second--, mp[it->first-1]+=2, sum++;
	}
	
	vector<ll> vec;
	for(auto p : mp)
	{
		rep(i, 1, p.second) vec.push_back(p.first);
	}
	reverse(all(vec));
	
	cout << "Yes" << endl;
	for(auto x : vec) cout << x << " ";
	cout << endl;
	
	return 0;
}