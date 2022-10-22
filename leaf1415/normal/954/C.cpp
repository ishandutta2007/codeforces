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
ll a[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i], a[i]--;
	
	set<ll> S;
	rep(i, 1, n-1){
		if(a[i] == a[i+1]){
			cout << "NO" << endl;
			return 0;
		}
		if(abs(a[i]-a[i+1]) > 1) S.insert(abs(a[i]-a[i+1]));
	}
	if(S.size() == 0){
		cout << "YES" << endl;
		cout << 1 << " " << 1000000000 << endl;
		return 0;
	}
	if(S.size() >= 2){
		cout << "NO" << endl;
		return 0;
	}
	
	ll x = *S.begin();
	rep(i, 1, n-1){
		if(abs(a[i]-a[i+1]) == 1 && a[i]/x != a[i+1]/x){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	cout << 1000000000 << " " << x << endl;
	
	return 0;
}