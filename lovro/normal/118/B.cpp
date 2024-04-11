#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;


int main() {
  cin.sync_with_stdio(0);

  int n;
  cin >> n;
  for (int row=-n; row<=n; ++row) {
    int dist = n - abs(row);
    string padding(2*(n-dist), ' ');
    cout << padding;
    bool first = true;
    for (int i=-dist; i<=dist; ++i) {
      if (!first) {
        cout << ' ';
      }
      first = false;
      cout << dist - abs(i);
    }
    cout << endl;
  }

  return 0;
}