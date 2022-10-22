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
ll a[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	rep(i, 1, n) cin >> a[i];
	
	rep(i, 1, n) if(a[i] >= k) {
		cout << 0 << endl;
		return 0;
	}
	
	ll p;
	rep(i, 1, n){
		if(a[i]){
			p = i;
			break;
		}
	}
	rep(i, 1, n-(p-1)) a[i] = a[i+p-1];
	n -= p-1;
	
	if(n == 2){
		cout << (k-a[2]+a[1]-1)/a[1] << endl;
		return 0;
	}
	
	if(n >= 4){
		for(ll t = 1; ; t++){
			rep(i, 1, n){
				a[i] += a[i-1];
				if(a[i] >= k){
					cout << t << endl;
					return 0;
				}
			}
		}
	}
	
	ll ub = sqrt(2*k/a[1])+5, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(a[3] + mid*a[2] + mid*(mid+1)/2 * a[1] >= k) ub = mid;
		else lb = mid;
	}
	cout << ub << endl;
	
	return 0;
}