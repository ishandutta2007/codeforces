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

ll n, k;
ll a[205];
vector<ll> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	rep(i, 1, n) cin >> a[i];
	ll b;
	rep(i, 1, k){
		cin >> b;
		vec.push_back(b);
	}
	sort(all(vec));
	
	rep(i, 1, n){
		if(a[i] == 0){
			a[i] = vec.back();
			vec.pop_back();
		}
	}
	rep(i, 1, n-1){
		if(a[i] > a[i+1]){
			outl("Yes");
			return 0;
		}
	}
	outl("No");
	
	return 0;
}