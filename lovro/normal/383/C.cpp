#include <cstring>
#include <ctime>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

#define repeat(n) for (int repc = (n); repc > 0; --repc)
#define ZERO(v) memset((v), 0, sizeof (v))

const int MAXN = 200005;

int initval[MAXN];
vector<int> adj[MAXN];
vector<pair<int, int> > op1[MAXN];
vector<int> op2[MAXN];
vector<int> ans;

struct Loga {
  Loga(int n) : n(n) { ZERO(arr); }

  void add(int p, int x) {
    for (++p; p <= n; p += p&-p) {
      arr[p] += x;
    }
  }

  int query(int p) const {
    int ans = 0;
    for (++p; p > 0; p -= p&-p) {
      ans += arr[p];
    }
    return ans;
  }

  int n;
  int arr[MAXN+1];
} *loga[2];

void dfs(int pos, int parent, int depth_even) {
  for (pair<int, int> p : op1[pos]) {
    loga[depth_even]->add(p.first, p.second);
  }

  for (int time : op2[pos]) {
    ans[time] =
      initval[pos]
      + loga[depth_even]->query(time)
      - loga[!depth_even]->query(time);
  }

  for (int ch : adj[pos]) {
    if (ch != parent) {
      dfs(ch, pos, !depth_even);
    }
  }

  for (pair<int, int> p : op1[pos]) {
    loga[depth_even]->add(p.first, -p.second);
  }
}

int main() {
  cin.sync_with_stdio(0);

  int N, M;
  cin >> N >> M;
  for (int i=1; i<=N; ++i) {
    cin >> initval[i];
  }

  repeat (N-1) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> all_op2;
  for (int time=1; time<=M; ++time) {
    int op, x;
    cin >> op >> x;
    if (op == 1) {
      int val;
      cin >> val;
      op1[x].push_back(make_pair(time, val));
    } else {
      all_op2.push_back(time);
      op2[x].push_back(time);
    }
  }

  loga[0] = new Loga(M+1);
  loga[1] = new Loga(M+1);
  ans.resize(M+1);
  dfs(1, -1, true);

  for (int time : all_op2) {
    cout << ans[time] << '\n';
  }
  return 0;
}