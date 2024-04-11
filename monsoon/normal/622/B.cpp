#include <cstdio>
#include <algorithm>
using namespace std;

int h,m,delta;

int main() {
  scanf("%d:%d %d",&h,&m,&delta);
  int t = h*60+m+delta;
  printf("%02d:%02d\n", t/60%24, t%60);
}