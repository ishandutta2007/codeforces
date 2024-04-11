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

string s;
ll a[5005], b[5005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	ll n = s.size();
	s = "#" + s;
	
	rep(i, 1, n){
		a[i] = a[i-1], b[i] = b[i-1];
		if(s[i] == 'a') a[i]++;
		else b[i]++;
	}
	
	ll ans = inf;
	rep(i, 0, n){
		rep(j, 0, n){
			if(i+j > n) continue;
			chmin(ans, b[i] + b[n]-b[n-j] + a[n-j]-a[i]);
		}
	}
	cout << n-ans << endl;
	
	return 0;
}