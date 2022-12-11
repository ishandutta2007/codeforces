#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

vector<lli> p;
lli x, a;
lli y, b;
lli k;

lli gcd(lli a, lli b) {
  if (a == 0)
    return b;
  return gcd(b%a, a);
}

lli lcm(lli a, lli b) {
  return a*b/gcd(a,b);
}

bool works(int amt) {
  int amtX = amt/a;
  int amtY = amt/b;
  int amtXY = amt/lcm(a, b);
  amtX -= amtXY;
  amtY -= amtXY;
  lli ans=0;
  int cur=p.size()-1;
  for (int i=0; i<amtXY; ++i) {
    ans += (x+y)*(p[cur]/100);
    cur--;
  }
  for (int i=0; i<amtX; ++i) {
    ans += x*(p[cur]/100);
    cur--;
  }
  for (int i=0; i<amtY; ++i) {
    ans += y*(p[cur]/100);
    cur--;
  }
  return ans >= k;
}

void solve() {
  int n;
  cin >> n;
  p.resize(n);
  for (lli& i : p)
    cin >> i;
  cin >> x >> a;
  cin >> y >> b;
  cin >> k;
  if (x<y) {
    swap(x, y);
    swap(a, b);
  }
  
  sort(p.begin(), p.end());
  int l=0, r=n+1;
  while (r-l>1) {
    int m=(l+r)/2;
    if (!works(m))
      l=m;
    else
      r=m;
  }
  if (l==n)
    cout << -1 << endl;
  else
    cout << l+1 << endl;
}

int main() {
  int q;
  cin >> q;
  for (int i=0; i<q; ++i) {
    solve();
  }
}