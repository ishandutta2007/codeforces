#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double PI = 3.1415926535897932, eps = 1e-8;

struct Point{
	double x, y;
	Point(double x_ = 0.0, double y_ = 0.0): x(x_), y(y_) {}
}p[100005], t;

typedef Point Vector;
Vector operator - (const Point &l, const Point &r){
	return Vector(l.x - r.x, l.y - r.y);
}
int dcmp(double x){return fabs(x) < eps ? 0 : (x > 0.0 ? 1 : -1);}
double Dot(const Vector &l, const Vector &r){
	return l.x * r.x + l.y * r.y;
}
double Length(const Vector &x){
	return sqrt(Dot(x, x));
}
double Cross(const Vector &l, const Vector &r){
	return l.x * r.y - l.y * r.x;
}
bool operator == (const Vector &l, const Vector &r){
	return dcmp(l.x - r.x) == 0 && dcmp(l.y - r.y) == 0;
}
double DistanceToSegment(const Point &p, const Point &u, const Point &v){
	if(u == v) return Length(p - u);
	Vector a = v - u, b = p - u, c = p - v;
	if(dcmp(Dot(a, b)) < 0) return Length(b);
	if(dcmp(Dot(a, c)) > 0) return Length(c);
	return fabs(Cross(a, b)) / Length(a);
}
double getDist(Point &a, Point &b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}
int main(){
	int i, n; double minDist, maxDist;
	scanf("%d%lf%lf", &n, &t.x, &t.y);
	for(i = 1; i <= n; ++ i)
		scanf("%lf%lf", &p[i].x, &p[i].y);
	minDist = DistanceToSegment(t, p[1], p[n]);
	maxDist = getDist(t, p[n]);
	for(i = 1; i < n; ++ i){
		minDist = min(minDist, DistanceToSegment(t, p[i], p[i + 1]));
		maxDist = max(maxDist, getDist(t, p[i]));
	}
	printf("%.15f\n", PI * (maxDist * maxDist - minDist * minDist));
	return 0;
}