#define NDEBUG
#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>

// <lib>
typedef uint64_t u64;
#define repeat(n) for (int _repc = (n); _repc > 0; --_repc)
// </lib>
using namespace std;

vector<vector<int> > adj;

struct DfsResult {
  u64 sumd[2];
  u64 n[2];
};

DfsResult ans;

DfsResult dfs(int a, int parent, const int mydep) {
  const int mypar = mydep % 2;
  DfsResult myres;
  memset(&myres, 0, sizeof(myres));
  for (int b : adj[a]) {
    if (b == parent) {
      continue;
    }
    DfsResult sub = dfs(b, a, mydep + 1);
    ans.sumd[0] += sub.sumd[ mypar] - sub.n[ mypar] * mydep;
    ans.n[0] += sub.n[mypar];
    ans.sumd[1] += sub.sumd[!mypar] - sub.n[!mypar] * mydep;
    ans.n[1] += sub.n[!mypar];
    for (int i=0; i<2; ++i) {
      for (int j=0; j<2; ++j) {
        ans.sumd[i^j] += myres.n[i] * (sub.sumd[j] - sub.n[j] * mydep);
        ans.sumd[i^j] += sub.n[j] * (myres.sumd[i] - myres.n[i] * mydep);
        ans.n[i^j] += myres.n[i] * sub.n[j];
      }
    }
    for (int i=0; i<2; ++i) {
      myres.sumd[i] += sub.sumd[i];
      myres.n[i] += sub.n[i];
    }
  }
  myres.sumd[mypar] += mydep;
  myres.n[mypar] += 1;
  return myres;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  adj.resize(n);
  repeat (n-1) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(0, -1, 0);
  u64 out =
    ans.sumd[0] / 2 +
    (ans.sumd[1] + ans.n[1]) / 2;
  cout << out << '\n';
}