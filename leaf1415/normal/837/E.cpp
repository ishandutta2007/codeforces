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

ll x, y;

ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

ll get(ll b, ll i)
{
	if(i == 1) return inf;
	return b - b/i*i;
}

ll calc(ll a, ll b)
{
	if(b == 0) return 0;
	if(b % a == 0) return b / a;
	
	ll g = gcd(a, b);
	ll A = a / g, B = b / g;
	
	ll ret = A;
	for(ll i = 1; i*i <= A; i++){
		if(A % i == 0){
			chmin(ret, get(B, i));
			chmin(ret, get(B, A/i));
		}
	}
	return ret + calc(a, b - ret * g);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> x >> y;
	cout << calc(x, y) << endl;
	
	return 0;
}