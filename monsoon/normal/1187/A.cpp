#include <cstdio>
#include <algorithm>
using namespace std;

int _,n,s,t;

int main() {
  scanf("%d",&_);
  while(_-->0) {
    scanf("%d%d%d",&n,&s,&t);
    int ans = max(n-s, n-t) + 1;
    printf("%d\n",ans);
  }
}