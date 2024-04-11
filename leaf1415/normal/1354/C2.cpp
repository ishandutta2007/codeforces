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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define PI 3.141592653589793238
#define eps 1e9

using namespace std;
typedef pair<llint, llint> P;

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


llint T;
llint n;
double th, l, r;

vec2d rot(vec2d &v, double th)
{
	return vec2d(cos(th)*v.x-sin(th)*v.y, sin(th)*v.x+cos(th)*v.y);
}

double calc(double x)
{
	double minX = inf, minY = inf, maxX = -inf, maxY = -inf;
	vec2d v = vec2d(cos(x), sin(x)) * r;
	for(int i = 0; i < 2*n; i++){
		maxX = max(maxX, v.x);
		maxY = max(maxY, v.y);
		minX = min(minX, v.x);
		minY = min(minY, v.y);
		v = rot(v, th);
	}
	return max(maxX-minX, maxY-minY);
}

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		
		th = PI / n, l = 1.0 / (2*tan(th/2)), r  = 1.0 / (2*sin(th/2));
		
		double ub = th, lb = 0, mid1, mid2;
		for(int i = 0; i < 100; i++){
			mid1 = (ub+2*lb)/3, mid2 = (2*ub+lb)/3;
			double res = calc(mid1), res2 = calc(mid2);
			if(res > res2) lb = mid1;
			else ub = mid2;
		}
		printf("%.11f\n", calc(lb));
	}
	flush(cout);
	
	return 0;
}