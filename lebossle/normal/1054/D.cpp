#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long int lli;

int main() {
  lli n, k;
  cin >> n >> k;
  map<lli, lli> count;
  count[0]++;
  lli cur = 0;
  for (int i=0; i<n; ++i) {
    lli x;
    cin >> x;
    cur ^= x;
    cur = min(cur, cur^((1<<k)-1));
    count[cur]++;
  }
  lli ans = n*(n+1)/2;
  for (auto p : count) {
    lli c = p.second;
    lli fh = c/2, sh = c-fh;
    ans -= fh*(fh-1)/2;
    ans -= sh*(sh-1)/2;
  }
  cout << ans << endl;
}