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
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll h, w;
ll a[505][505], b[505][505];

ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll l = 1;
	rep(i, 1, 16) l = l*i / gcd(l, i);
	
	cin >> h >> w;
	rep(y, 1, h) rep(x, 1, w) cin >> a[x][y];
	
	rep(y, 1, h) rep(x, 1, w){
		b[x][y] = l;
		if((x+y)%2) b[x][y] -= a[x][y]*a[x][y]*a[x][y]*a[x][y];
	}
	
	rep(y, 1, h){
		rep(x, 1, w){
			cout << b[x][y] << " ";
		}
		cout << endl;
	}
	
	return 0;
}