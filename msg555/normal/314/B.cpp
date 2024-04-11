#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {
  int B, D; cin >> B >> D;
  string A, C; cin >> A >> C;

  for(int i = 0; i < C.size(); i++) {
    bool ok = false;
    for(int j = 0; !ok && j < A.size(); j++) {
      ok = C[i] == A[j];
    }
    if(!ok) {
      cout << "0\n";
      return 0;
    }
  }

  long long x = -1;
  map<pair<int, int>, pair<long long, long long> > tmmp;
  for(long long i = 0; ; i++) {
    for(++x; C[i % C.size()] != A[x % A.size()]; x++);

    if(x >= A.size() * B) {
      cout << i / C.size() / D << '\n';
      return 0;
    }

    pair<int, int> ky = make_pair(i % C.size(), x % A.size());
    if(tmmp.find(ky) != tmmp.end()) {
      long long ml = (A.size() * B - x - 1) / (x - tmmp[ky].second);
      i += ml * (i - tmmp[ky].first);
      x += ml * (x - tmmp[ky].second);
    } else {
      tmmp[ky] = make_pair(i, x);
    }
  }

  return 0;
}