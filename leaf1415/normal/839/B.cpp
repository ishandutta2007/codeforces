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
ll a[105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	rep(i, 1, k) cin >> a[i];
	
	rep(i, 0, n){
		ll cnt4 = i, cnt2 = 2*n + (n-i), cnt1 = n-i;
		
		bool flag = true;
		rep(j, 1, k){
			ll rem = a[j];
			ll x = min(cnt4, rem/4);
			cnt4 -= x, rem -= x*4;
			
			x = min(cnt2, rem/2);
			cnt2 -= x, rem -= x*2;
			
			x = min(cnt1, rem);
			cnt1 -= x, rem -= x;
			
			x = min(cnt2, rem);
			cnt2 -= x, rem -= x;
			
			if(rem){
				flag = false;
				break;
			}
		}
		if(flag){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	
	return 0;
}