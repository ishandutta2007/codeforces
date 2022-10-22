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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n, s;
ll g = 1000000;
vector<P> vec[2];
ll a[1000005], b[1000005];

void calc(vector<P> &vec, ll a[], double T)
{
	rep(i, 1, 1000000) a[i] = 0;

	for(auto p : vec){
		ll x = p.first, v = p.second;
		if((s+v)*T < x) continue;
		if(v*T >= x){
			a[1]++, a[g]--;
			break;
		}

		double ub = g, lb = x, mid;
		rep(i, 0, 50){
			mid = (ub+lb)/2;
			double t = (double)(mid-x)/(s-v);
			if(t+(x-v*t)/(s+v) <= T) lb = mid;
			else ub = mid;
		}
		ll r = ceil(lb)+1e-9;
		//cout << T << " " << x << " " << r << endl;
		a[x]++, a[r]--;
	}
	rep(i, 1, 1000000) a[i] += a[i-1];
}

bool check(double T)
{
	calc(vec[0], a, T);
	calc(vec[1], b, T);
	rep(i, 1, 999999) if(a[i] && b[g-i]) return true;
	return false;
}

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> s;
	ll x, v, t;
	rep(i, 1, n){
		cin >> x >> v >> t;
		if(t == 1) vec[0].push_back(P(x, v));
		else vec[1].push_back(P(g-x, v));
	}

	double ub = 1e6, lb = 0, mid;
	for(int i = 0; i < 50; i++){
		mid = (ub+lb)/2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	printf("%.11f\n", ub);

	return 0;
}