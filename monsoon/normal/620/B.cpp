#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1000100, SEG[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
int a,b,seg[N],ans;

int main() {
  scanf("%d%d",&a,&b);
  for(int i=1;i<=b;++i) { seg[i] = seg[i/10] + SEG[i%10]; }
  for(int i=a;i<=b;++i) { ans += seg[i]; }
  printf("%d\n",ans);
}