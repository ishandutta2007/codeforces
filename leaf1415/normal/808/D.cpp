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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size()-1; (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n;
ll a[100005];
multiset<ll> L, R;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	
	ll sum = 0;
	rep(i, 1, n) sum += a[i];
	if(sum % 2){
		cout << "NO" << endl;
		return 0;
	}
	
	rep(i, 1, n) R.insert(a[i]);
	ll s = 0;
	rep(i, 1, n){
		if(s == sum-s){
			cout << "YES" << endl;
			return 0;
		}
		ll d = abs(s-sum+s) / 2;
		if(s > sum-s){
			if(L.count(d)){
				cout << "YES" << endl;
				return 0;
			}
		}
		else{
			if(R.count(d)){
				cout << "YES" << endl;
				return 0;
			}
		}
		s += a[i];
		L.insert(a[i]);
		R.erase(R.lower_bound(a[i]));
	}
	cout << "NO" << endl;
	
	return 0;
}