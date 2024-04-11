#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 1000100;
int n,perm[N],vis[N],cyc;

int main() {
  scanf("%d",&n);
  cyc = n&1;
  REP(i,n) scanf("%d",&perm[i]);
  REP(i,n) if (!vis[i]) {
    int j = i;
    do {
      vis[j] = 1;
      j = perm[j];
    } while (!vis[j]);
    cyc ^= 1;
  }
  if (cyc) puts("Petr");
  else puts("Um_nik");
}