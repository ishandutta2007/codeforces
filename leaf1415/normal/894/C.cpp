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
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n;
ll s[1005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> s[i];
	
	rep(i, 1, n){
		if(s[i] % s[1]){
			cout << -1 << endl;
			return 0;
		}
	}
	
	vector<ll> vec;
	rep(i, 1, n){
		vec.push_back(s[1]);
		vec.push_back(s[i]);
	}
	
	cout << vec.size() << endl;
	for(auto x : vec) cout << x << " "; cout << endl;
	
	return 0;
}