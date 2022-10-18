#define NDEBUG
#include <algorithm>
#include <functional>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

// <lib>
#define ALL(x) (x).begin(), (x).end()
// </lib>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<pair<int, int> > order(n);
  for (int i=0; i<n; ++i) {
    cin >> a[i];
    order[i] = make_pair(a[i], i);
  }
  sort(ALL(order), greater<pair<int, int> >());

  vector<char> win(n+1);
  for (const auto& pp : order) {
    int val, pos;
    tie(val, pos) = pp;
    for (int i=pos-val; i>=0; i-=val) {
      if (a[i] > val && !win[a[i]]) {
        win[val] = true;
        break;
      }
    }
    for (int i=pos+val; i<n; i+=val) {
      if (a[i] > val && !win[a[i]]) {
        win[val] = true;
        break;
      }
    }
  }

  for (int i=0; i<n; ++i) {
    cout << "BA"[win[a[i]]];
  }
  cout << '\n';
}