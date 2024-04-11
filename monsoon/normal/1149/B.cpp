#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPDN(i,n) for(int i=(n)-1;i>=0;--i)

const int N=110000,M=260, infty=1000000000;
int n,q,len[3];
char s[N],ss[3][M];
int memo[M][M][M],nextt[N][26];
bool ismemo[M][M][M];

int calc(int a0, int a1, int a2) {
  int a[3] = {a0,a1,a2};
  if (ismemo[a0][a1][a2]) return memo[a0][a1][a2];

  int best = infty;
  REP(i,3) if (a[i] > 0) {
    --a[i];
    int w = calc(a[0], a[1], a[2]);
    if (w < n) {
      best = min(best, nextt[w][ss[i][a[i]]-'a'] + 1);
    }
    ++a[i];
  }

  ismemo[a0][a1][a2] = 1;
  return memo[a0][a1][a2] = best;
}

int main() {
  scanf("%d%d%s",&n,&q,s);
  ismemo[0][0][0] = 1;
  memo[0][0][0] = 0;

  REP(j,26) nextt[n][j] = infty;
  REPDN(i,n) {
    REP(j,26) nextt[i][j] = nextt[i+1][j];
    nextt[i][s[i]-'a'] = i;
  }

  REP(i,q) {
    char c; int k; scanf(" %c%d",&c,&k); --k;
    if (c == '-') {

      if (k==0) { REP(a1,len[1]+1) REP(a2,len[2]+1) ismemo[len[0]][a1][a2] = 0; }
      else if (k==1) { REP(a0,len[0]+1) REP(a2,len[2]+1) ismemo[a0][len[1]][a2] = 0; }
      else { REP(a0,len[0]+1) REP(a1,len[1]+1) ismemo[a0][a1][len[2]] = 0; }

      len[k]--;
    } else {
      char ch; scanf(" %c",&ch);
      ss[k][len[k]++] = ch;
    }
    int w = calc(len[0], len[1], len[2]);
    puts(w == infty ? "NO" : "YES");
  }
}