#pragma GCC optimize("Ofast, unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

struct roflan {
  vector<deque<int>> have;
  deque<int> elems;
  int * a;
  int sum;
  pair<int, int> seg;
  roflan(int * a, int n) : a(a), sum(0), seg({1, 0}) {
    have.resize(n + 1);
  };
  void go(pair<int, int> new_seg) {
    while (seg.S < new_seg.S) {
      add_right(a[++seg.S]);
    }
    while (seg.F > new_seg.F) {
      add_left(a[--seg.F]);
    }
    while (seg.S > new_seg.S) {
      del_right();
      seg.S--;
    }
    while (seg.F < new_seg.F) {
      del_left();
      seg.F++;
    }
  }
  void add_left(int x) {
    elems.push_front(x);
    if (SZ(have[x]) >= 2) {
      sum -= have[x].back() - have[x].front();
    }
    have[x].push_front(seg.F);
    if (SZ(have[x]) >= 2) {
      sum += have[x].back() - have[x].front();
    }
  }
  void add_right(int x) {
    elems.push_back(x);
    if (SZ(have[x]) >= 2) {
      sum -= have[x].back() - have[x].front();
    }
    have[x].push_back(seg.S);
    if (SZ(have[x]) >= 2) {
      sum += have[x].back() - have[x].front();
    }
  }
  void del_left() {
    int x = elems.front();
    elems.pop_front();
    if (SZ(have[x]) >= 2) {
      sum -= have[x].back() - have[x].front();
    }
    have[x].pop_front();
    if (SZ(have[x]) >= 2) {
      sum += have[x].back() - have[x].front();
    }
  }
  void del_right() {
    int x = elems.back();
    elems.pop_back();
    if (SZ(have[x]) >= 2) {
      sum -= have[x].back() - have[x].front();
    }
    have[x].pop_back();
    if (SZ(have[x]) >= 2) {
      sum += have[x].back() - have[x].front();
    } 
  }
};

const int INF = 1e9 + 10;
const int N = 35010;
const int K = 110;
int a[N], dp[N][K], lst[N];


void calc(int level, int l, int r, int optl, int optr, roflan& state) {
  if (l > r) {
    return;
  }
  int mid = (l + r) / 2;
  pair<int, int> best = {INF, optl - 1};
  for (int i = optl; i <= min(mid, optr); i++) {
    state.go({i, mid});
    best = min(best, {dp[i - 1][level - 1] + state.sum, i});
  }
  dp[mid][level] = best.F;
  calc(level, l, mid - 1, optl, best.S, state);
  calc(level, mid + 1, r, best.S, optr, state);
}
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int csum = 0;
  for (int i = 1; i <= n; i++) {
    if (lst[a[i]] != 0) {
      csum += i - lst[a[i]];
    }
    dp[i][1] = csum;
    lst[a[i]] = i;
  } 
  roflan state(a, n); 
  for (int i = 2; i <= k; i++) {
    state.go({1, 0});
    for (int j = 1; j < i; j++) {
      dp[j][i] = INF;
    }
    calc(i, i, n, 1, n, state);
  }
  cout << dp[n][k] << '\n';
}