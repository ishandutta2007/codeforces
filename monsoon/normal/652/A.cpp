#include <bits/stdc++.h>
using namespace std;

int h1,h2,a,b;

int main() {
  scanf("%d%d%d%d",&h1,&h2,&a,&b);
  int d = h2-h1, ans;
  if (8*a >= d) ans = 0;
  else if (a <= b) ans = -1;
  else {
    d -= 8*a;
    int v = 12*(a-b);
    ans = (d + v-1) / v;
  }
  printf("%d\n",ans);
}