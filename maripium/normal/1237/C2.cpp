#include <bits/stdc++.h>

using namespace std;

const int N = 50500;

struct Point {
   int x, y, z, id;
   Point(int x = 0, int y = 0, int z = 0, int id = 0) :
      x(x), y(y), z(z), id(id) {}
   bool operator < (const Point &p) const {
      return make_tuple(x, y, z) < make_tuple(p.x, p.y, p.z);
   }
};

bool erased[N];
Point ps[N];

void Erase(Point p, Point q) {
   erased[p.id] = true;
   erased[q.id] = true;
   cout << p.id + 1 << " " << q.id + 1 << "\n";
}

void solve(vector<Point> ps) { // x = y =
   sort(ps.begin(), ps.end());
   while (ps.size() > 1) {
      Point p = ps.back();
      ps.pop_back();
      Point q = ps.back();
      ps.pop_back();
      Erase(p, q);
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   int n;
   cin >> n;
   for (int i = 0; i < n; ++i) {
      cin >> ps[i].x >> ps[i].y >> ps[i].z;
      ps[i].id = i;
   }
   {
      map<pair<int, int>, vector<Point>> mps;
      for (int i = 0; i < n; ++i) {
         mps[{ps[i].x, ps[i].y}].emplace_back(ps[i]);
      }
      for (auto &q : mps) {
         solve(q.second);
      }
   }
   {
      map<int, vector<Point>> mps;
      for (int i = 0; i < n; ++i) {
         if (!erased[ps[i].id]) {
            mps[ps[i].x].emplace_back(ps[i]);
         }
      }
      for (auto &q : mps) {
         solve(q.second);
      }
   }
   vector<Point> mps;
   for (int i = 0; i < n; ++i) {
      if (!erased[ps[i].id]) {
         mps.emplace_back(ps[i]);
      }
   }
   solve(mps);
}