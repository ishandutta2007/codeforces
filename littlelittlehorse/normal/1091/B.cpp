#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
typedef complex<double> Complex;
#define fi first
#define se second
#define ins insert
#define pb push_back
inline char GET_CHAR(){
  const int maxn = 131072;
  static char buf[maxn],*p1=buf,*p2=buf;
  return p1==p2&&(p2=(p1=buf)+fread(buf,1,maxn,stdin),p1==p2)?EOF:*p1++;
}
inline int getInt() {
  int res(0);
  char c = getchar();
  while(c < '0') c = getchar();
  while(c >= '0') {
    res = res * 10 + (c - '0');
    c = getchar();
  }
  return res;
}

inline int fastpo(int x, int n, int mod) {
  int res(1);
  while(n) {
    if(n & 1) {
      res = res * (LL)x % mod;
    }
    x = x * (LL) x % mod;
    n /= 2;
  }
  return res;
}
const int N = 300033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int a[1001][2], b[1001][2];
map<pair<int, int>, int> c;
int main() {
  scanf("%d", &n);
  c.clear();
  for (int i = 1; i <= n; i++)
    scanf("%d%d", &a[i][0], &a[i][1]);
  for (int i = 1; i <= n; i++)
    scanf("%d%d", &b[i][0], &b[i][1]);
  bool ok = true;
  for (int i = 1; i <= n; i++) 
    for (int j = 1; j <= n; j++) {
      pair<int, int> tmp(a[i][0] + b[j][0], a[i][1] + b[j][1]);
      if (++c[tmp] == n) {
        printf("%d %d\n", tmp.first, tmp.second);
        return 0;
      }
    }
}