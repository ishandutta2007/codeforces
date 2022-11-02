#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct point {
       double x, y;
       point(double xx = 0, double yy = 0): x(xx), y(yy) {}
       point operator - (const point & p) const{
             return(point(x - p.x, y - p.y));
       }
       bool operator == (const point & p) {
            return x == p.x && y == p.y;
       }
       bool perp(const point & p) {
            return x * p.x + y * p.y == 0;
       }
       double dist() {
              return sqrt(x * x + y * y);
       }
};

point p[8];

bool square(int a, int b, int c, int d) {
     vector<point> t;
     t.push_back(p[a]);
     t.push_back(p[b]);
     t.push_back(p[c]);
     t.push_back(p[d]);
     bool ok = true;
     ok = ((p[b] - p[a] == p[c] - p[d]) && (p[c] - p[b] == p[d] - p[a]));
     point v1 = p[b] - p[a], v2 = p[c] - p[b], v3 = p[d] - p[c], v4 = p[a] - p[d];
     ok = ok && (v1.perp(v4) && v1.perp(v2) && v2.perp(v3) && v3.perp(v4));
     ok = ok && (v1.dist() == v2.dist() && v2.dist() == v3.dist() &&  v3.dist() == v4.dist());
     double res = 0;
     for(int i = 0; i < 4; ++i)
             res += t[i].x * t[(i + 1) % 4].y - t[i].y * t[(i + 1) % 4].x;
     return (ok && res != 0);
}

bool rect(int a, int b, int c, int d) {
     vector<point> t;
     t.push_back(p[a]);
     t.push_back(p[b]);
     t.push_back(p[c]);
     t.push_back(p[d]);
     point v1 = p[b] - p[a], v2 = p[c] - p[b], v3 = p[d] - p[c], v4 = p[a] - p[d];
     bool ok = true;
     ok = (v1 == point(0, 0) - v3 && v2 == point(0, 0) - v4);
     ok = ok && (v1.perp(v4) && v1.perp(v2) && v2.perp(v3) && v3.perp(v4));
     ok = ok && (v1.dist() == v3.dist() && v2.dist() == v4.dist());
     double res = 0;
     for(int i = 0; i < 4; ++i)
             res += t[i].x * t[(i + 1) % 4].y - t[i].y * t[(i + 1) % 4].x;
     return (ok && res != 0);
}

int main() {
    for(int i = 0; i < 8; ++i)
            cin >> p[i].x >> p[i].y;
    vector<int>  o(8);
    for(int i = 0; i < 8; ++i) 
            o[i] = i;
    bool ok = true;
    for(int i = 0; i < 100000; ++i) {
            bool b1 = square(o[0], o[1], o[2], o[3]), b2 = rect(o[4], o[5], o[6], o[7]);
            if(b2 && b1) {
                  cout << "YES" << endl;
                  for(int i = 0; i < 4; ++i)
                          cout << o[i] + 1 << " ";
                  cout << endl;
                  for(int i = 4; i < 8; ++i)
                          cout << o[i] + 1 <<  " ";
                  cout << endl;
                  cin >> b1;
                  return 0;
            }
            next_permutation(o.begin(), o.end());
    }
    cout << "NO" << endl;
    cin >> o[0];
    return 0;
}