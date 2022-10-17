#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 2100;
const string DIG[] = {
  "1110111", "0010010", "1011101", "1011011", "0111010",
  "1101011", "1101111", "1010010", "1111111", "1111011"
};
int n,k,cache[N][N],cache2[N][N];
char s[10];
int now[N],dig[N];
bool has[N][N];

int encode(const char* s) {
  int mask = 0;
  REP(i,7) { mask |= int(s[i]-'0')<<i; }
  return mask;
}

int dp(int i, int j) {
  if (j < 0) return 0;
  if (i == n) { return j == 0; }
  if (has[i][j]) { return cache[i][j]; }

  int ok = 0, ilex = -1;
  REP(c,10) {
    if ((dig[c] & now[i]) == now[i]) {
      int ile = __builtin_popcountl(dig[c] & ~now[i]);
      if (dp(i+1, j - ile)) {
        ok = c+1;
        ilex = ile;
      }
    }
  }
  has[i][j] = 1;
  cache[i][j] = ok;
  cache2[i][j] = ilex;
  return ok;
}

int main() {
  scanf("%d%d",&n,&k);
  REP(c,10) dig[c] = encode(DIG[c].c_str());
  REP(i,n) {
    scanf("%s",s);
    now[i] = encode(s);
  }

  int w = dp(0, k);
  if (w == 0) { puts("-1"); }
  else {
    int j = k;
    REP(i,n) {
      putchar('0' + cache[i][j]-1);
      j -= cache2[i][j];
    }
    puts("");
  }
}