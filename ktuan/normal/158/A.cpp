#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  Rep(i,n) cin >> a[i];
  int res = k, r2 = 0;
  Rep(i,n) if (i >= k && a[i] == a[k - 1]) ++res;
  Rep(i,n) if (a[i] != 0) ++r2;
  cout << min(res, r2) << endl;
  return 0;
}