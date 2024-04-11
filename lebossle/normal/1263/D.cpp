#include <bits/stdc++.h>
using namespace std;

class Dsu {
 public:
  Dsu(int n) :
    parent(n),
    rank(n, 0) {
    iota(parent.begin(), parent.end(), 0);
  }
  int get(int x) {
    if (parent[x] == x)
      return x;
    parent[x] = get(parent[x]);
    return parent[x];
  }
  void merge(int a, int b) {
    a = get(a);
    b = get(b);
    if (rank[a] < rank[b])
      swap(a, b);
    parent[b] = a;
    if (rank[a] == rank[b])
      rank[a]++;
  }
 private:
  vector<int> parent;
  vector<int> rank;
};

void solve() {
  int n;
  while (cin >> n) {
    vector<string> pass(n);
    for (string& s : pass)
      cin >> s;
    Dsu dsu('z'-'a'+1);
    for (string s : pass)
      for (int i=1; i<s.size(); ++i)
        dsu.merge(s[i]-'a', s[i-1]-'a');
    set<int> ans;
    for (string s : pass)
      ans.insert(dsu.get(s[0]-'a'));
    cout << ans.size() << endl;
  }
}

int main() {
  solve();
}