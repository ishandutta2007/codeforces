#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define debug(x) cerr << #x << " = " << (x) << endl;
#define ALL(x) (x).begin(), (x).end()

const int MAXK = 3005;
int which[MAXK][MAXK];

bool vborder[MAXK][MAXK], hborder[MAXK][MAXK];
short vcum[MAXK][MAXK], hcum[MAXK][MAXK];

char grid[MAXK][MAXK];
int area[MAXK][MAXK];

struct Rect {
  int x1, y1, x2, y2;
};

int getarea(int x1, int y1, int x2, int y2) {
  return area[y2][x2] - area[y2][x1] - area[y1][x2] + area[y1][x1];
}

int main() {
  cin.sync_with_stdio(0);

  int n;
  cin >> n;
  vector<Rect> rects(n);
  vector<vector<int> > x2s_by_y1(MAXK);
  for (int i=0; i<n; ++i) {
    Rect &r = rects[i];
    cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;
    x2s_by_y1[r.y1].push_back(r.x2);
  }

  for (const Rect r : rects) {
    for (int x=r.x1; x<r.x2; ++x) {
      hborder[r.y1][x] = 1;
      hborder[r.y2][x] = 1;
    }
    for (int y=r.y1; y<r.y2; ++y) {
      vborder[r.x1][y] = 1;
      vborder[r.x2][y] = 1;
    }

    for (int y=r.y1; y<r.y2; ++y) {
      for (int x=r.x1; x<r.x2; ++x) {
        grid[y][x] = 1;
      }
    }
  }

  for (int i=0; i<=3002; ++i) {
    sort(ALL(x2s_by_y1[i]));
    for (int j=1; j<=3002; ++j) {
      hcum[i][j] = hcum[i][j-1] + hborder[i][j-1];
      vcum[i][j] = vcum[i][j-1] + vborder[i][j-1];
    }
  }

  for (int y=1; y<=3002; ++y) {
    for (int x=1; x<=3002; ++x) {
      area[y][x] = grid[y-1][x-1] + area[y-1][x] + area[y][x-1] - area[y-1][x-1];
    }
  }

  bool foundit = false;
  Rect outrect;
  for (const Rect r : rects) {
    const int y1 = r.y1, x1 = r.x1;
    vector<int> &x2s = x2s_by_y1[y1];
    vector<int>::const_iterator xptr = lower_bound(ALL(x2s), x1+1);
    for (; xptr != x2s.end(); ++xptr) {
      const int x2 = *xptr;
      int len = x2 - x1;
      int y2 = y1 + len;
      if (hcum[y1][x2] - hcum[y1][x1] == len &&
          hcum[y2][x2] - hcum[y2][x1] == len &&
          vcum[x1][y2] - vcum[x1][y1] == len &&
          vcum[x2][y2] - vcum[x2][y1] == len &&
          getarea(x1, y1, x2, y2) == len*len) {
        // debug(x1);
        // debug(y1);
        // debug(x2);
        // debug(y2);
        foundit = true;
        outrect.x1 = x1; outrect.x2 = x2;
        outrect.y1 = y1; outrect.y2 = y2;
        break;
      }
    }

    if (foundit) {
      break;
    }
  }

  if (foundit) {
    vector<int> rect_ids;
    for (int i=0; i<n; ++i) {
      const Rect r = rects[i];
      if (r.x1 >= outrect.x1 && r.x2 <= outrect.x2 &&
          r.y1 >= outrect.y1 && r.y2 <= outrect.y2) {
        rect_ids.push_back(i+1);
      }
    }
    int ans = rect_ids.size();
    cout << "YES " << ans << '\n';
    cout << rect_ids[0];
    for (int i=1; i<ans; ++i) {
      cout << ' ' << rect_ids[i];
    }
    cout << '\n';
  } else {
    cout << "NO\n";
  }

  return 0;
}