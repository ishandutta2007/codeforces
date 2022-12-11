#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  set<int> poss;
  for (int i=0; i<n; ++i) {
    int r;
    cin >> r;
    set<int> cur;
    for (int j=0; j<r; ++j) {
      int x;
      cin >> x;
      cur.insert(x);
    }
    set<int> next;
    if (i == 0)
      next = cur;
    else {
      for (int x : cur)
        if (poss.count(x))
          next.insert(x);
    }
    poss = next;
  }
  for (int x : poss)
    cout << x << ' ';
  cout << endl;
}