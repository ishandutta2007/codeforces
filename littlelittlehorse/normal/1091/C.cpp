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
LL a[1000001];
int cnt;
void calc(LL n, LL i) {
  LL f = 1, e = (n - 1) / i * i + 1, x = (n - 1) / i + 1;
  a[++cnt] = (f + e) * x / 2; 
}

int main() {
  LL n;
  scanf("%lld", &n);
  cnt = 0; 
  for (int i = 1; i * i <= n; i++) 
    if (!(n % i)) {
      calc(n, i);
      if (i * i != n)
        calc(n, n / i);
    }
  sort(a + 1, a + cnt + 1);
  for (int i = 1; i <= cnt; i++)
    printf("%lld ", a[i]);
  printf("\n");
}