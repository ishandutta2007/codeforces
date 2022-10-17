#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

char a[10],b[10];

int main() {
  REP(i,6) scanf(" %c%c",&a[i],&b[i]);
  int ok=0;
  REP(i,5) if (a[i+1] == a[0] || b[i+1] == b[0]) ok=1;
  puts(ok ? "YES" : "NO");
}