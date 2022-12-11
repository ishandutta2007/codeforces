#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii,ii> rect;

const int MAX = 15e8;

rect intersect(rect a, rect b) {
  return rect(ii(max(a.first.first, b.first.first), max(a.first.second, b.first.second)),
              ii(min(a.second.first, b.second.first), min(a.second.second, b.second.second)));
}

bool isEmpty(rect x) {
  return (x.first.first > x.second.first) || (x.first.second > x.second.second);
}

int main() {
  int n;
  cin >> n;
  vector<rect> v(n);
  for (int i=0; i<n; ++i)
    cin >> v[i].first.first >> v[i].first.second >> v[i].second.first >> v[i].second.second;
  int minx2 = MAX, maxx1 = -MAX;
  int miny2 = MAX, maxy1 = -MAX;
  for (int i=0; i<n; ++i) {
    minx2 = min(minx2, v[i].second.first);
    miny2 = min(miny2, v[i].second.second);
    maxx1 = max(maxx1, v[i].first.first);
    maxy1 = max(maxy1, v[i].first.second);
  }
  if (maxx1 <= minx2) {
    if (maxy1 <= miny2) {
      cout << maxx1 << " " << maxy1 << endl;
      return 0;
    }
    maxx1 = MAX;
    minx2 = MAX;
  } else {
    maxy1 = MAX;
    miny2 = MAX;
  }
  rect cur(ii(-MAX, -MAX), ii(MAX, MAX)), candmax, candmin;
  for (int i=0; i<n; ++i) {
    if (v[i].first.first == maxx1 || v[i].first.second == maxy1) {
      maxx1 = MAX;
      maxy1 = MAX;
      candmax = v[i];
    } else if (v[i].second.first == minx2 || v[i].second.second == miny2) {
      minx2 = MAX;
      miny2 = MAX;
      candmin = v[i];
    } else {
      cur = intersect(cur, v[i]);
    }
  }
  candmax = intersect(cur, candmax);
  candmin = intersect(cur, candmin);
  if (!isEmpty(candmax)) {
    cout << candmax.first.first << ' ' << candmax.first.second << endl;
  } else {
    cout << candmin.first.first << ' ' << candmin.first.second << endl;
  }
}