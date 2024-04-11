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
ll h, w;
ll l[100005], r[100005], u[100005], d[100005];
ll L, R, U, D;
vector<ll> lvec, rvec, uvec, dvec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> w >> h;
	ll lx, ly, rx, ry;
	rep(i, 1, n){
		cin >> lx >> ly >> rx >> ry;
		l[i] = min(lx, rx);
		r[i] = max(lx, rx);
		u[i] = min(ly, ry);
		d[i] = max(ly, ry);
		lvec.push_back(l[i]);
		rvec.push_back(r[i]);
		uvec.push_back(u[i]);
		dvec.push_back(d[i]);
	}
	sort(all(lvec));
	sort(all(rvec));
	sort(all(uvec));
	sort(all(dvec));
	
	cin >> L >> R >> U >> D;
	
	rep(i, 1, n){
		ll lcnt = lower_bound(all(lvec), r[i]) - lvec.begin();
		ll rcnt = rvec.end() - upper_bound(all(rvec), l[i]);
		if(l[i] < r[i]) lcnt--, rcnt--;
		
		ll ucnt = lower_bound(all(uvec), d[i]) - uvec.begin();
		ll dcnt = dvec.end() - upper_bound(all(dvec), u[i]);
		if(u[i] < d[i]) ucnt--, dcnt--;
		
		//cout << lcnt << " " << rcnt << " " << ucnt << " " << dcnt << endl;
		
		if(lcnt == L && rcnt == R && ucnt == U && dcnt == D){
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	
	return 0;
}