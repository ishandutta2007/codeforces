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

ll h, m, s, t1, t2;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> m >> s >> t1 >> t2;
	ll n = 3600 * 12;
	ll sec = h*3600 + m*60 + s;
	t1 *= 3600, t2 *= 3600;
	ll a[] = {sec, sec * 12 % n, sec * 720 % n};
	
	if(t1 > t2) swap(t1, t2);
	
	bool flag = true;
	rep(i, 0, 2){
		rep(i, 0, 2) if(t1 <= a[i] && a[i] <= t2) flag = false;
	}
	if(flag){
		cout << "YES" << endl;
		return 0;
	}
	
	flag = true;
	rep(i, 0, 2){
		rep(i, 0, 2) if(t2 <= a[i] || a[i] <= t1) flag = false;
	}
	if(flag){
		cout << "YES" << endl;
		return 0;
	}
	
	cout << "NO" << endl;
	
	return 0;
}