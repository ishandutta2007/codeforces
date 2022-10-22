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

ll a, b, f, k;
vector<ll> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b >> f >> k;
	rep(i, 1, k){
		if(i % 2) vec.push_back(f), vec.push_back(a-f);
		else vec.push_back(a-f), vec.push_back(f);
	}
	rep(i, 0, (int)vec.size()-1){
		if(i%2 && i+1 < vec.size()) vec[i] += vec[i+1], vec[i+1] = 0;
	}
	
	ll x = b, ans = 0;
	for(auto d : vec)
	{
		if(d > b){
			cout << -1 << endl;
			return 0;
		}
		if(d > x) x = b, ans++;
		x -= d;
	}
	cout << ans << endl;
	
	return 0;
}