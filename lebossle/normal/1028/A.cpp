#include <iostream>
#include <vector>

using namespace std;

int main() {
  int r, c;
  cin >> r >> c;
  vector<string> v(r);
  for (int i=0; i<r; ++i)
    cin >> v[i];
  int x1=-1, y1, x2=-1, y2;
  for (int i=0; i<r; ++i)
    for (int j=0; j < c; ++j)
      if (v[i][j] == 'B') {
        if (x1 == -1) {
          x1 = i;
          y1 = j;
        }
        x2=i;
        y2=j;
      }
  cout << (x1+x2)/2+1 << endl;
  cout << (y1+y2)/2+1 << endl;
}