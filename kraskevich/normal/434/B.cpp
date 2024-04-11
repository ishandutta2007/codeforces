#include <bits/stdc++.h>

using namespace std;

template<class T>
void print(const vector<T>& v) {
  cerr << "{";
  for (T x : v)
    cerr << x << " ";
  cerr << "}";
  cerr << endl;
}

int get_area(const vector<int>& h, int must_have) {
  int n = h.size();
  static vector<int> big_left;
  static vector<int> big_right;
  static vector<pair<int, int>> s;
  s.clear();
  s.reserve(n);
  big_left.assign(n, -1);
  big_right.assign(n, n);
  for (int i = 0; i < n; i++) {
    while (!s.empty() && s.back().first >= h[i])
      s.pop_back();
    if (!s.empty())
      big_left[i] = s.back().second;
    s.push_back(make_pair(h[i], i));
  }
  s.clear();
  s.reserve(n);
  for (int i = n - 1; i >= 0; i--) {
    while (!s.empty() && s.back().first >= h[i])
      s.pop_back();
    if (!s.empty())
      big_right[i] = s.back().second;
    s.push_back(make_pair(h[i], i));
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    int l = big_left[i];
    int r = big_right[i];
    if (l < must_have && must_have < r)
      res = max(res, h[i] * (r - l - 1));
  }
  return res;
}

const int N = 1111;

bool was[N][N];
int go_left[N][N];
int go_right[N][N];
int go_down[N][N];
int go_up[N][N];

void calc_row(int x, int m) {
  int last = -1;
  for (int j = 0; j < m; j++) {
    if (was[x][j])
      last = j;
    go_left[x][j] = last;
  }
  last = m;
  for (int j = m - 1; j >= 0; j--) {
    if (was[x][j])
      last = j;
    go_right[x][j] = last;
  }
}

void calc_col(int y, int n) {
  int last = -1;
  for (int i = 0; i < n; i++) {
    if (was[i][y])
      last = i;
    go_up[i][y] = last;
  }
  last = n;
  for (int i = n - 1; i >= 0; i--) {
    if (was[i][y])
      last = i;
    go_down[i][y] = last;
  }
}

void change(int x, int y, int n, int m) {
  was[x][y] ^= 1;
  calc_row(x, m);
  calc_col(y, n);
}

int get_max_area(int x, int y, int n, int m) {
  //Upper rectangle.
  vector<int> h(m);
  for (int j = 0; j < m; j++)
    h[j] = x - go_up[x][j];
  int res = get_area(h, y);
  //Lower rectangle.
  for (int j = 0; j < m; j++)
    h[j] = go_down[x][j] - x;
  res = max(res, get_area(h, y));
  h.resize(n);
  //Left rectangle.
  for (int i = 0; i < n; i++)
    h[i] = y - go_left[i][y];
  res = max(res, get_area(h, x));
  //Right rectangle.
  for (int i = 0; i < n; i++)
    h[i] = go_right[i][y] - y;
  res = max(res, get_area(h, x));
  return res;
}

void init(int n, int m) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      go_left[i][j] = -1;
      go_right[i][j] = m;
      go_down[i][j] = n;
      go_up[i][j] = -1;
    }
}

int main() {
  ios_base::sync_with_stdio(0);
  #ifdef TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif // TEST

  int n, m, q;
  cin >> n >> m >> q;
  init(n, m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      if (!x)
        was[i][j] = true;
    }
  for (int i = 0; i < n; i++)
    calc_row(i, m);
  for (int i = 0; i < m; i++)
    calc_col(i, n);
  for (int i = 0; i < q; i++) {
    int t, x, y;
    cin >> t >> x >> y;
    --x;
    --y;
    if (t == 1)
      change(x, y, n, m);
    else
      cout << get_max_area(x, y, n, m) << "\n";
  }

  return 0;
}