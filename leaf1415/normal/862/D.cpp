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
ll ans[2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	cin >> n;
	
	ll res, res2;
	string s;
	rep(i, 0, n-1) s += "0";
	cout << "?" << " " << s << endl;
	cin >> res;
	
	s[0] = '1';
	cout << "?" << " " << s << endl;
	cin >> res2;
	
	ll c;
	if(res < res2) ans[0] = 1, c = 0;
	else ans[1] = 1, c = 1;
	
	ll all;
	rep(i, 0, n-1) s[i] = c+'0';
	cout << "?" << " " << s << endl;
	cin >> all;
	
	ll ub = n-1, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		rep(i, 0, mid) s[i] = c+'0';
		rep(i, mid+1, n-1) s[i] = (1-c)+'0';
		cout << "?" << " " << s << endl;
		cin >> res;
		if(all + (n-1)-mid == res) ub = mid;
		else lb = mid;
	}
	ans[1-c] = ub+1;
	
	cout << "!" << " " << ans[0] << " " << ans[1] << " " << endl;
	
	return 0;
}