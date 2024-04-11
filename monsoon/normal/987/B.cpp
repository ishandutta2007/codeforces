#include <cstdio>
#include <algorithm>
using namespace std;

const int infty = 1000000000;
int x,y;

int reorder(int x) {
  if (x==3) return 0;
  else if (x==2 || x==4) return 1;
  else if (x==1) return infty+10;
  else return x;
}

int main() {
  scanf("%d%d",&x,&y);
  if (reorder(x) < reorder(y)) puts(">");
  else if (reorder(x) > reorder(y)) puts("<");
  else puts("=");
}