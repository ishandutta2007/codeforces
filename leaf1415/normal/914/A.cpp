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
set<ll> S;
ll a[1005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	rep(i, 0, 1000) S.insert(i*i);
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	sort(a+1, a+n+1);
	
	for(int i = n; i >= 1; i--){
		if(S.count(a[i]) == 0){
			cout << a[i] << endl;
			return 0;
		}
	}
	
	return 0;
}