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
ll x[1005][5];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) rep(j, 0, 4) cin >> x[i][j];
	
	if(n >= 100){
		cout << 0 << endl;
		return 0;
	}
	
	vector<ll> vec;
	rep(i, 1, n){
		bool flag = true;
		rep(j, 1, n){
			rep(k, 1, n){
				if(i == j || j == k || k == i) continue;
				ll sum = 0;
				rep(l, 0, 4) sum += (x[j][l]-x[i][l]) * (x[k][l]-x[i][l]);
				if(sum > 0) flag = false;
			}
		}
		if(flag) vec.push_back(i);
	}
	cout << vec.size() << endl;
	for(auto x : vec) cout << x << " "; cout << endl;
	
	return 0;
}