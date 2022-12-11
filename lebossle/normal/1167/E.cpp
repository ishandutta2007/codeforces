#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main() {
  ios::sync_with_stdio(false);
  lli n, x;
  cin >> n >> x;
  vector<int> inp(n);
  for (int i=0; i<n; ++i)
    cin >> inp[i];
  if (n == 1) {
    cout << x*(x+1)/2 << endl;
    return 0;
  }
  vector<int> id(n);
  for (int i=0; i<n; ++i)
    id[i] = i;
  sort(id.begin(), id.end(), [&](int a, int b) {
    if (inp[a] != inp[b])
      return inp[a] < inp[b];
    return a < b;
  });
  lli l=1, r=n;
  while (l+1<n && id[l-1] <= id[l])
    l++;
  lli ans=0;
  for (; l>=0; --l) {
    if (l>0 && inp[id[l]] == inp[id[l-1]])
      continue;
    while (l < r-1 && (l == 0 || id[l-1] <= id[r-1]) && (r == n || id[r-1] <= id[r]))
      r--;
    ans += (x-inp[id[r-1]]+1) * (inp[id[l]] - (l==0 ? 0 : inp[id[l-1]]));
  }
  if (r == 1 && id[0] <= id[1]) {
    lli d = inp[id[0]]-1;
    ans += d*(d+1)/2;
    for (int i=1; i<n; ++i) {
      d = inp[id[i]]-inp[id[i-1]]-1;
      ans += d*(d+1)/2;
    }
    d = x-inp[id[n-1]];
    ans += d*(d+1)/2;
  }
  cout << ans << endl;
}