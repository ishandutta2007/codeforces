#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define repeat(n) for ( int repc = (n); repc > 0; --repc )

bool can(const vector<int> &r, int howmany, vector<int> *out) {
  if (out != NULL) {
    out->clear();
  }
  int total = 0;
  for (int i=0; i<(int)r.size(); ) {
    int j;
    for (j=i+1; j<(int)r.size() && r[i] == r[j]; ++j) ;
    int assigned = min(j-i, howmany);
    total += assigned;

    if (out != NULL) {
      repeat (assigned) {
        out->push_back(r[i]);
      }
    }
    i = j;
  }
  if (out != NULL) {
    out->resize(3*howmany);
  }
  return total >= 3*howmany;
}

int main() {
  cin.sync_with_stdio(0);

  int n;
  cin >> n;
  vector<int> r(n);
  for (int i=0; i<n; ++i) {
    cin >> r[i];
  }
  sort(r.begin(), r.end(), greater<int>());

  int lo = 0, hi = n;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (can(r, mid, NULL)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  cout << lo << '\n';

  vector<int> out;
  can(r, lo, &out);

  for (int i=0; i<lo; ++i) {
    cout << out[i] << ' ' << out[lo+i] << ' ' << out[2*lo+i] << '\n';
  }
  return 0;
}