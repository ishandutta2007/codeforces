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

ll gcd(ll a, ll b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

ll n;
ll a, b;
set<ll> S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	rep(i, 1, 1000000) S.insert(i*i*i);
	
	cin >> n;
	rep(i, 1, n){
		cin >> a >> b;
		if(S.count(a*b) == 0){
			cout << "No" << "\n";
			continue;
		}
		
		ll g = gcd(a, b);
		a /= g, b /= g;
		
		if(gcd(a, g) == a && gcd(b, g) == b) cout << "Yes" << "\n";
		else cout << "No" << "\n";
	}
	flush(cout);
	
	return 0;
}