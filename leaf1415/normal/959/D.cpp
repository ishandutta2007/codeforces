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
ll a[100005], b[100005];
int prime[2000005];
bool used[2000005];
set<ll> S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	rep(i, 2, 1005){
		if(prime[i]) continue;
		for(int j = 2*i; j < 2000005; j+=i) prime[j] = i;
	}
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	
	bool flag = false; ll pt = 2;
	rep(i, 1, n){
		ll x;
		
		if(flag){
			while(used[pt]) pt++;
			x = pt;
		}
		else{
			rep(j, a[i], 2000000){
				if(!used[j]){
					x = j;
					break;
				}
			}
		}
		
		b[i] = x;
		if(a[i] < b[i]) flag = true;
		
		while(prime[x]){
			ll p = prime[x];
			for(int j = p; j < 2000005; j+=p) used[j] = true;
			x /= p;
		}
		for(int j = x; j < 2000005; j+=x) used[j] = true;
	}
	rep(i, 1, n) cout << b[i] << " "; cout << endl;
	
	return 0;
}