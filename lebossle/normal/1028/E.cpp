#include <iostream>
#include <vector>

using namespace std;

typedef long long int lli;

int main() {
  int n;
  cin >> n;
  vector<lli> v(n);
  for (int i=0; i<n; ++i)
    cin >> v[i];
  lli stval = -1;
  for (int i=0; i<n; ++i)
    stval = max(stval, v[i]);
  int ind = -1;
  for (int i=0; i<n; ++i)
    if (v[i] == stval && v[(i+n-1)%n] != stval)
      ind = i;
  if (ind == -1) {
    if (stval == 0) {
      cout << "YES" << endl;
      for (int i=0; i<n; ++i)
        cout << (i==0 ? "" : " ") << 1;
      cout << endl;
    } else {
      cout << "NO" << endl;
    }
    return 0;
  }
  vector<lli> sol(n);
  sol[ind] = stval;
  lli cur = stval;
  for (int i=(ind+n-1)%n; i != ind; i = (i+n-1)%n) {
    if (v[i] == 0 && cur == stval)
      cur = 2*stval;
    else
      cur += v[i];
    sol[i] = cur;
  }
  cout << "YES" << endl;
  for (int i=0; i<n; ++i)
    cout << (i==0 ? "" : " ") << sol[i];
  cout << endl;
}