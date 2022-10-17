#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

const int N = 1000100;
int n,a[N],vis[N],c,ans[N];
vector<int> cycles[N],groups[N];

int main() {
  scanf("%d",&n);
  REP(i,n) { scanf("%d",&a[i]); --a[i]; }
  REP(i,n) if (!vis[i]) {
    int j = i;
    do {
      vis[j] = 1;
      cycles[c].push_back(j);
      j = a[j];
    } while (j != i);
    groups[ cycles[c].size() ].push_back(c);
    ++c;
  }

  REP(i,n+1) {
    if (i%2 == 1) {
      FORE(j,groups[i]) {
        vector<int>& v = cycles[*j];
        vector<int> w(i);
        int k=0;
        REP(_,i) {
          w[k] = v[_];
          k = (k+2)%i;
        }
        REP(_,i) {
          ans[w[_]] = w[(_+1)%i];
        }
      }
    } else {
      if (groups[i].size()%2 == 1) {
        puts("-1"); exit(0);
      }
      REP(j,groups[i].size()/2) {
        vector<int>& v1 = cycles[groups[i][2*j]];
        vector<int>& v2 = cycles[groups[i][2*j+1]];
        vector<int> w(2*i);
        int k=0;
        REP(_,i) {
          w[k++] = v1[_];
          w[k++] = v2[_];
        }
        REP(_,2*i) {
          ans[w[_]] = w[(_+1)%(2*i)];
        }
      }
    }
  }
  REP(i,n) printf("%d ",ans[i]+1);
  puts("");
}