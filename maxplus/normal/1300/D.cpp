#include <iostream>

using namespace std;

struct Point {
  int64_t x, y;
  
  friend Point operator-(Point a, const Point& b) {
    a.x -= b.x;
    a.y -= b.y;
    return a;
  }
  
  friend Point operator+(Point a, const Point& b) {
    a.x += b.x;
    a.y += b.y;
    return a;
  }
  
  friend bool operator==(const Point& a, const Point& b) {
    return a.x == b.x && a.y == b.y;
  }
};

using namespace std;

Point a[100000];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  bool flag = n % 2 == 0;
  for (int i = 1; i * 2 < n; ++i) {
    flag &= a[i] + a[n / 2 + i] == a[0] + a[n / 2];
  }
  cout << (flag == 1? "Yes": "No") << '\n';
}