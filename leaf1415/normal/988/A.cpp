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

ll n, k;
set<int> S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	llint a; vector<ll> vec;
	rep(i, 1, n){
		cin >> a;
		if(S.count(a) == 0) vec.push_back(i), S.insert(a);
	}
	if(vec.size() < k) cout << "NO" << endl;
	else{
		cout << "YES" << endl;
		rep(i, 0, k-1) cout << vec[i] << " ";
		cout << endl;
	}

	return 0;
}