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
ll k;
ll a[65];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	rep(i, 1, 60){
		rep(j, 1, i) a[i] += (1LL<<(i-j))*j;
		a[i] += i;
	}
	//rep(i, 1, 60) cout << a[i] << endl;
	
	cin >> T;
	while(T--){
		cin >> k;
		if(k % 2){
			cout << -1 << endl;
			continue;
		}
		
		vector<ll> vec;
		for(int i = 60; i >= 1; i--){
			while(k >= a[i]){
				vec.push_back(i);
				k -= a[i];
			}
		}
		vector<ll> ans;
		for(auto x : vec)
		{
			ans.push_back(1);
			rep(i, 1, x-1) ans.push_back(0);
		}
		cout << ans.size() << endl;
		for(auto x : ans) cout << x << " "; cout << endl;
	}
	
	return 0;
}