#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define foreach(i,c) for ( typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i )

int main() {
  cin.sync_with_stdio(0);

  int n;
  cin >> n;
  vector<int> tosolve(n);
  for (int i=0; i<n; ++i) {
    cin >> tosolve[i];
  }
  sort(tosolve.begin(), tosolve.end());
  int tnow = -350, solved = 0, penalty = 0;
  foreach (it, tosolve) {
    tnow += *it;
    if (tnow > 360) {
      break;
    }
    ++solved;
    penalty += max(0, tnow);
  }
  cout << solved << ' ' << penalty << '\n';
  
  return 0;
}