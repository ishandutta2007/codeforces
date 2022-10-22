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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size(); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define ceildiv(x, y) (((x)+(y)-1) / (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
bool exceed(ll x, ll y, ll m){return x >= m / y + 1;} 

ll T;
ll x, y, p, q;

ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> x >> y >> p >> q;
		if(p == 0){
			if(x == 0) cout << 0 << endl;
			else cout << -1 << endl;
			continue;
		}
		if(p == q){
			if(x == y) cout << 0 << endl;
			else cout << -1 << endl;
			continue;
		}
		ll g = gcd(p, q); p /= g, q /= g;
		
		ll k = ceildiv(y-x,q-p);
		chmax(k, ceildiv(x, p));
		chmax(k, ceildiv(y, q));
		cout << k*q - y << endl;
	}
	
	return 0;
}