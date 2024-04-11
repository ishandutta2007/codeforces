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
#define eps 1e-11

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
bool exceed(ll x, ll y, ll m){return x >= m / y + 1;} 

struct vec2d{
	double x, y;
	vec2d(){}
	vec2d(double x, double y){
		this->x = x, this->y = y;
	}
	double add(double a, double b){
		if(fabs(a+b) < eps * (fabs(a) + fabs(b))) return 0.0;
		return a+b;
	}
	vec2d operator+(vec2d ope){
		return vec2d(add(x, ope.x), add(y, ope.y));
	}
	vec2d operator-(vec2d ope){
		return vec2d(add(x, -ope.x), add(y, -ope.y));
	}
	vec2d operator*(double t){
		return vec2d(x*t, y*t);
	}
	vec2d operator/(double t){
		return vec2d(x/t, y/t);
	}
	double dot(vec2d ope){
		return add(x*ope.x, y*ope.y);
	}
	double cross(vec2d ope){
		return add(x*ope.y, -y*ope.x);
	}
	double norm(){
		double d2 = dot(*this);
		if(d2 > 0) return sqrt(d2);
		return 0.0;
	}
};

double distPP(vec2d p, vec2d q){
	return (p-q).norm();
}

double distLP(vec2d p, vec2d q, vec2d x)
{
	return fabs( (x-p).cross(q-p) / distPP(p, q) );
}

ll n;
vec2d p[1005];

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	rep(i, 0, n-1) cin >> p[i].x >> p[i].y;
	
	double ans = inf;
	rep(i, 0, n-1){
		rep(j, 2, n-1){
			chmin(ans, distLP(p[i], p[(i+1)%n], p[(i+j)%n])/2);
		}
	}
	rep(i, 0, n-1){
		chmin(ans, distLP(p[i], p[(i+2)%n], p[(i+1)%n])/2);
	}
	rep(i, 0, n-1) rep(j, 0, n-1){
		if(i != j) chmin(ans, distPP(p[i], p[j])/2);
	}
	
	printf("%.11f\n", ans);
	
	return 0;
}