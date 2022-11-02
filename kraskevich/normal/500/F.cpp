#include <bits/stdc++.h>

using namespace std;


const int N = 4000 + 10;
const int Q = 20000 + 10;

struct Item {
  int t;
  int cost;
  int h;
  
  Item(): t(0) ,cost(0), h(0) {}
  
  Item(int t): t(t), cost(0), h(0) {}
  
  bool operator<(const Item& i) const {
    return t < i.t;
  }
};

Item items[N];
int dpL[N][N];
int dpR[N][N];
int n, p, q;

int getDpL(int pos, int b, int p, int low, int high) {
  p--;
  if (p < 0)
    return 0;
  if (items[p].t < low)
    return 0;
  return dpL[p][b];
}

int getDpR(int pos, int b, int p, int low, int high) {
  if (p == n)
    return 0;
  if (items[p].t > high)
    return 0;
  return dpR[p][b];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> p;
  for (int i = 0; i < n; i++)
    cin >> items[i].cost >> items[i].h >> items[i].t;
  sort(items, items + n);
  for (int i = 0; i < n; i++) {
    bool f = i == 0 || items[i].t / p != items[i - 1].t / p;
    for (int b = 0; b < N; b++) {
      if (!f)
    dpL[i][b] = max(dpL[i][b], dpL[i - 1][b]);
      if (items[i].cost <= b)
    if (f)
      dpL[i][b] = max(dpL[i][b], items[i].h);
    else
      dpL[i][b] = max(dpL[i][b], dpL[i - 1][b - items[i].cost] + items[i].h);
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    bool f = i == n - 1 || items[i].t / p != items[i + 1].t / p;
    for (int b = 0; b < N; b++) {
      if (!f)
    dpR[i][b] = max(dpR[i][b], dpR[i + 1][b]);
      if (items[i].cost <= b)
    if (f)
      dpR[i][b] = max(dpR[i][b], items[i].h);
    else
      dpR[i][b] = max(dpR[i][b], dpR[i + 1][b - items[i].cost] + items[i].h);
    }
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    int high = a;
    int low = max(0, a - p + 1);
    int mid = low;
    if (mid % p != 0)
      mid += p - mid % p;
    int res = 0;
    int p1 = upper_bound(items, items + n, Item(high)) - items;
    int p2 = lower_bound(items, items + n, Item(low)) - items;
    for (int k = 0; k <= b; k++) {
      int r = getDpR(low, k, p2, low, mid - 1);
      int l = getDpL(high, b - k, p1, mid, high);
      res = max(res, l + r);
    }
    cout << res << "\n";
  }
  return 0;
}