#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

const int N = 200100;
int n,x;
vector<int> ans;

void go(int bit, int which) {
  if (bit == -1) return;
  else if (bit == which) {
    go(bit-1, -1);
  } else {
    go(bit-1, which);
    ans.push_back(1<<bit);
    go(bit-1, which);
  }
}

int main() {
  scanf("%d%d",&n,&x);
  if (x >= (1<<n)) {
    go(n-1, -1);
  } else {
    int b=0; while (x%2==0) { ++b; x/=2; }
    go(n-1, b);
  }
  printf("%d\n",(int)ans.size());
  FORE(i,ans) printf("%d ",*i);
  printf("\n");
}