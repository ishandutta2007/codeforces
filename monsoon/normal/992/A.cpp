#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

int n;
set<int> s;

int main() {
  scanf("%d",&n);
  REP(i,n) {
    int a; scanf("%d",&a);
    s.insert(a);
  }
  s.erase(0);
  printf("%d\n", (int)s.size());
}