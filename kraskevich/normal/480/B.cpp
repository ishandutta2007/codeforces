#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  int n, l, x, y;
  cin >> n >> l >> x >> y;
  vector<int> a(n);
  set<int> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s.insert(a[i]);
  }
  bool canX = false;
  bool canY = false;
  for (int i = 0; i < n; i++) {
    if (s.count(a[i] - x))
      canX = true;
    if (s.count(a[i] - y))
      canY = true;
  }
  set<int> cX;
  set<int> cY;
  if (!canX) {
    for (int i = 0; i < n; i++) {
      if (a[i] - x >= 0)
	cX.insert(a[i] - x);
      if (a[i] + x <= l)
	cX.insert(a[i] + x);
    }
  }
  if (!canY) {
    for (int i = 0; i < n; i++) {
      if (a[i] - y >= 0)
	cY.insert(a[i] - y);
      if (a[i] + y <= l)
	cY.insert(a[i] + y);
    }
  }
  vector<int> res;
  if (!canX && !canY) {
    for (int elem : cX)
      if (cY.count(elem)) {
	res.push_back(elem);
	break;
      }
    if (!res.size()) {
      res.push_back(*cX.begin());
      res.push_back(*cY.begin());
    }
  } else {
    if (cX.size())
      res.push_back(*cX.begin());
    if (cY.size())
      res.push_back(*cY.begin());
  }
  cout << res.size() << endl;
  for (int elem : res)
    cout << elem << " ";
  cout << endl;
  return 0;
}