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
ll a[1<<17];
ll x[1<<17];
int used[1<<17];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	rep(i, 2, n){
		cout << "XOR" << " " << 1 << " " << i << endl;
		cin >> x[i];
	}
	ll p = 0, q = 0;
	rep(i, 1, n){
		if(used[x[i]]){
			p = i, q = used[x[i]];
			break;
		}
		used[x[i]] = i;
	}
	if(p != 0){
		cout << "AND" << " " << p << " " << q << endl;
		cin >> a[p];
		rep(i, 1, n) a[i] = a[p]^x[p]^x[i];
	}
	else{
		
		ll y = 0;
		rep(i, 2, n){
			if(x[i] != n-1){
				y = i;
				break;
			}
		}
		ll ay;
		cout << "AND" << " " << 1 << " " << y << endl;
		cin >> ay;
		
		p = used[n-1];
		
		ll res;
		cout << "AND" << " " << y << " " << p << endl;
		cin >> res;
		
		rep(i, 0, 15){
			if(ay&(1<<i)){
				a[1] |= (1<<i);
				continue;
			}
			if((x[y]&(1<<i)) == 0) continue;
			if((res&(1<<i)) == 0) a[1] |= 1<<i;
		}
		
		rep(i, 2, n) a[i] = a[1]^x[i];
	}
	
	cout << "! ";
	rep(i, 1, n) cout << a[i] << " "; cout << endl;
	
	return 0;
}