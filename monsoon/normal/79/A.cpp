#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

int x,y;
bool test(int xa, int ya) {
  bool ok = x >= xa && y >= ya;
  if (ok) { x -= xa; y -= ya; }
  return ok;
}
bool finish(const char* name) {
  puts(name); exit(0);
  return 0;
}

int main() {
  scanf("%d%d",&x,&y);
  int i=0;
  while (true) {
    if (i%2 == 0) {
      test(2, 2) || test(1, 12) || test(0, 22) || finish("Hanako");
    } else {
      test(0, 22) || test(1, 12) || test(2, 2) || finish("Ciel");
    }
    ++i;
  }
}