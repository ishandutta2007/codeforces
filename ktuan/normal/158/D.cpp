#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Fit(i,v) for(typeof(v.begin()) i=v.begin();i!=v.end();++i)

int n;
int a[20000], s[20000];

int main() {
  scanf("%d", &n);
  Rep(i,n) scanf("%d", &a[i]);
  int best = -1000000000;
  For(d,1,n) if (n % d == 0 && n / d >= 3) {
    Rep(i,n) s[i] = a[i] + ((i >= d) ? s[i - d] : 0);
    For(i,n-d,n-1) best = max(best, s[i]);
  }
  cout << best << endl;
  return 0;
}