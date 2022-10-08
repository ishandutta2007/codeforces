#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define Fit(i,v) for(typeof(v.begin()) i=v.begin();i!=v.end();++i)
#define fi first
#define se second

typedef pair<int,int> PII;

const char *a;
int n;
bool isPalin[2020][2020];
int F[2020], G[2020];
long long res = 0;

int main() {
  string s;
  cin >> s;
  a = s.c_str();
  n = s.length();
  Ford (i, n - 1, 0) For (j, i, n - 1) {
    if (a[i] == a[j]) isPalin[i][j] = (i + 1 <= j - 1) ? isPalin[i + 1][j - 1] : true;
  }
  Rep (i, n) Rep (j, n) if (isPalin[i][j]) {
    ++F[j];
    ++G[i];
  }
  Ford (i, n - 2, 0) G[i] += G[i + 1];
  For (i, 0, n - 1) res += F[i] * G[i + 1];
  cout << res << endl;
  return 0;
}