#include<bits/stdc++.h>
typedef long long LL;
using namespace std;

#define REMOVE_REDUNDANT

typedef double T;
const T EPS = 1e-7;
struct PT {
  T x, y;
  PT() {}
  PT(T x, T y) : x(x), y(y) {}
  bool operator<(const PT &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }
  bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
};

T cross(PT p, PT q) { return p.x*q.y-p.y*q.x; }
T area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }

double radius(PT a, PT b, PT c){
	double d1 = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	double d2 = sqrt((c.x-b.x)*(c.x-b.x)+(c.y-b.y)*(c.y-b.y));
	double d3 = sqrt((a.x-c.x)*(a.x-c.x)+(a.y-c.y)*(a.y-c.y));
	double d = d1*d2*d3;
	//cout << d << endl;
	double q = sqrt((d1+d2+d3)*(d1+d2-d3)*(d1+d3-d2)*(d2+d3-d1));
	//cout << q << endl;
	//cout << d/q << endl;
	return d/q;
}

#ifdef REMOVE_REDUNDANT
bool between(const PT &a, const PT &b, const PT &c) {
  return (fabs(area2(a,b,c)) < EPS && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0);
}
#endif

void ConvexHull(vector<PT> &pts) {
  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  vector<PT> up, dn;
  for (int i = 0; i < pts.size(); i++) {
    while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0.0) up.pop_back();
    while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0.0) dn.pop_back();
    up.push_back(pts[i]);
    dn.push_back(pts[i]);
  }
  pts = dn;
  for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);

#ifdef REMOVE_REDUNDANT
  if (pts.size() <= 2) return;
  dn.clear();
  dn.push_back(pts[0]);
  dn.push_back(pts[1]);
  for (int i = 2; i < pts.size(); i++) {
    if (between(dn[dn.size()-2], dn[dn.size()-1], pts[i])) dn.pop_back();
    dn.push_back(pts[i]);
  }
  if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
    dn[0] = dn.back();
    dn.pop_back();
  }
  pts = dn;
#endif
}

double maxr = 0.0;
int aa = -1;

int main(){
	vector<PT> c;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		double x, y, v;
		scanf("%lf%lf%lf",&x,&y,&v);
		//cin >> x >> y >> v;
		if(x+v <= 100000.0){
			PT k;
			k.x = x+v;
			k.y = y;
			c.push_back(k);
		} else {
			PT k;
			k.x = 100000.0;
			k.y = min(100000.0, y+(x+v-100000.0));
			c.push_back(k);
			k.y = max(0.0, y-(x+v-100000.0));
			c.push_back(k);
		}
		if(y+v <= 100000.0){
			PT k;
			k.x = x;
			k.y = y+v;
			c.push_back(k);
		} else {
			PT k;
			k.y = 100000.0;
			k.x = min(100000.0, x+(y+v-100000.0));
			c.push_back(k);
			k.x = max(0.0, x-(y+v-100000.0));
			c.push_back(k);
		}
		if(x-v >= 0.0){
			PT k;
			k.x = x-v;
			k.y = y;
			c.push_back(k);
		} else {
			PT k;
			k.x = 0.0;
			k.y = min(100000.0, y+(v-x));
			c.push_back(k);
			k.y = max(0.0, y-(v-x));
			c.push_back(k);
		}
		if(y-v >= 0.0){
			PT k;
			k.x = x;
			k.y = y-v;
			c.push_back(k);
		} else {
			PT k;
			k.y = 0.0;
			k.x = min(100000.0, x+(v-y));
			c.push_back(k);
			k.x = max(0.0, x-(v-y));
			c.push_back(k);
		}
	}
	ConvexHull(c);
	for(int i = 0; i < c.size(); i++){
		//cout << c[i].x << " " << c[i].y << endl;
	}
	int zz = c.size();
	for(int i = 0; i < zz; i++){
		double r = radius(c[i], c[(i+1)%zz], c[(i+2)%zz]);
		if(r > maxr){
			aa =i;
			maxr = r;
		}
	}
	/*cout << maxr << endl;
	cout << aa << endl;*/
	cout << c[aa].x << " " << c[aa].y << endl;
	cout << c[(aa+1)%zz].x << " " << c[(aa+1)%zz].y << endl;
	cout << c[(aa+2)%zz].x << " " << c[(aa+2)%zz].y << endl;


}