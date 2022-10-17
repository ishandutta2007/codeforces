#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 200100, LOGN = 18;
int n,q,a[N],b[N],idxa[N],idxb[N];
int qa[N],qb[N],idxqa[N];
int nxt[N],nxtup[LOGN][N];
int answer[N];

int main() {
  scanf("%d%d",&n,&q);
  REP(i,n) { scanf("%d%d",&a[i],&b[i]); }
  REP(i,q) { scanf("%d%d",&qa[i],&qb[i]); }
  REP(i,n) { idxa[i] = idxb[i] = i; }
  REP(i,q) { idxqa[i] = i; }
  sort(idxa,idxa+n, [](int i, int j) { return a[i] < a[j]; });
  sort(idxb,idxb+n, [](int i, int j) { return b[i] < b[j]; });
  sort(idxqa,idxqa+q, [](int i, int j) { return qa[i] < qa[j]; });

  int j = 0;
  pair<int,int> best = make_pair(-1, -1);
  REP(i,n) {
    while (j < n && a[idxa[j]] <= b[idxb[i]]) {
      best = max(best, make_pair(b[idxa[j]], idxa[j]));
      ++j;
    }
    nxt[idxb[i]] = best.second;
  }

  REP(v,n) { nxtup[0][v] = nxt[v]; }
  REP(i,LOGN-1) {
    REP(v,n) { nxtup[i+1][v] = nxtup[i][nxtup[i][v]]; }
  }

  j = 0;
  best = make_pair(-1, -1);
  REP(i,q) {
    while (j < n && a[idxa[j]] <= qa[idxqa[i]]) {
      best = max(best, make_pair(b[idxa[j]], idxa[j]));
      ++j;
    }

    int v = best.second, ans = 1;
    if (v == -1) {
      ans = -1;
    } else {
      for (int j=LOGN-1; j>=0; --j) {
        if (b[nxtup[j][v]] < qb[idxqa[i]]) {
          v = nxtup[j][v];
          ans += 1<<j;
        }
      }
      if (b[v] < qb[idxqa[i]]) { ans++; v = nxt[v]; }
      if (b[v] < qb[idxqa[i]]) { ans = -1; }
    }
    answer[idxqa[i]] = ans;
  }

  REP(i,q) { printf("%d\n", answer[i]); }
}