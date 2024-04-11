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

ll n, r;
ll f[55], s[55];
double p[55];
double dp[55][5005];

double calc(double x)
{
	for(int i = n-1; i >= 0; i--){
		rep(j, 0, r){
			double fdp, sdp;
			if(j+f[i+1] <= r) fdp = dp[i+1][j+f[i+1]]; else fdp = x;
			if(j+s[i+1] <= r) sdp = dp[i+1][j+s[i+1]]; else sdp = x;
			dp[i][j] = p[i+1] * (fdp + f[i+1]) + (1-p[i+1]) * (sdp + s[i+1]);
			if(i + j) chmin(dp[i][j], x);
		}
	}
	return dp[0][0];
}

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> r;
	rep(i, 1, n) cin >> f[i] >> s[i] >> p[i], p[i] /= 100;
	
	double ub = 1e18, lb = 0, mid;
	rep(i, 1, 100){
		mid = (ub+lb)/2;
		//cout << mid << " " << calc(mid) << endl;
		if(calc(mid) < mid) ub = mid;
		else lb = mid;
	}
	printf("%.11f\n", ub);
	
	return 0;
}