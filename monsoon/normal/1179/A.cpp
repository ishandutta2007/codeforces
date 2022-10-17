#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

const int N = 100100;
int n,q,a[N],ansa[N],ansb[N];
deque<int> d;

int main() {
  scanf("%d%d",&n,&q);
  REP(i,n) scanf("%d",&a[i]);
  REP(i,n) { d.push_back(a[i]); }
  REP(i,n) {
    ansa[i] = d.front(); d.pop_front();
    ansb[i] = d.front(); d.pop_front();
    if (ansa[i] > ansb[i]) { d.push_front(ansa[i]); d.push_back(ansb[i]); }
    else { d.push_front(ansb[i]); d.push_back(ansa[i]); }
  }
  REP(i,n) {
    a[i] = d.front(); d.pop_front();
  }

  REP(i,q) {
    ll v; scanf("%lld",&v); --v;
    if (v < n) {
      printf("%d %d\n",ansa[v],ansb[v]);
    } else {
      v -= n;
      int el = a[1 + v%(n-1)];
      printf("%d %d\n",a[0],el);
    }
  }
}