#include <bits/stdc++.h>

using namespace std;

const int P = 8092 + 10;

struct SegmTree {
  short pref[P];
  short suf[P];
  short best[P];
  bool all[P];
  int sz;
  
  SegmTree() {
    sz = 2000;
  }
  
  void merge(int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    all[i] = all[l] && all[r];
    pref[i] = pref[l];
    suf[i] = suf[r];
    best[i] = max(best[l], best[r]);
    best[i] = max((int)best[i], suf[l] + pref[r]);
    if (all[l])
      pref[i] = max((int)pref[i], pref[l] + pref[r]);
    if (all[r])
      suf[i] = max((int)suf[i], suf[l] + suf[r]);
  }
  
  int get_best() {
    return best[0];
  }
  
  void upd(int pos, int val) {
    upd(0, 0, sz - 1, pos, val);
  }
  
  void upd(int i, int l, int r, int pos, int val) {
    if (l == r) {
      pref[i] = val;
      suf[i] = val;
      best[i] = val;
      all[i] = val ? true : false;
      return;
    }
    int m = (l + r) / 2;
    if (pos <= m)
      upd(2 * i + 1, l, m, pos, val);
    else
      upd(2 * i + 2, m + 1, r, pos, val);
    merge(i);
  }
};

const int N = 2010;

int best[N];
SegmTree tree[N];
int height[N][N];
int pos[N][N];
vector<short> at[N][N];
char s[N][N];
int n, m, k;

void put(int row, int col, int new_h) {
  if (new_h >= height[row][col] || new_h >= best[row])
    return;
  int h = height[row][col];
  pos[row][at[row][h].back()] = pos[row][col];
  swap(at[row][h].back(), at[row][h][pos[row][col]]);
  at[row][h].pop_back();
  height[row][col] = new_h;
  pos[row][col] = at[row][new_h].size();
  at[row][new_h].push_back(col);
  tree[row].upd(col, 0);
}

void dec(int row) {
  while (best[row] > 0 && tree[row].get_best() < best[row]) {
    best[row]--;
    for (int col : at[row][best[row]])
      tree[row].upd(col, 1);
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++)
    scanf("%s", s[i]);
  for (int j = 0; j < m; j++) {
    int last = -1;
    for (int i = 0; i < n; i++) {
      if (s[i][j] == 'X')
	last = i;
      height[i][j] = i - last;
      pos[i][j] = at[i][height[i][j]].size();
      at[i][height[i][j]].push_back(j);
    }
  } 
  for (int i = 0; i < n; i++) 
    best[i] = i + 2;
  for (int i = 0; i < n; i++)
    dec(i);
  for (int i = 0; i < k; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    for (int row = x; row < n; row++) {
      put(row, y, row - x);
      dec(row);
    }
    printf("%d\n", *max_element(best, best + n));
  }
  //cerr << clock() - st << endl;
  return 0;
}