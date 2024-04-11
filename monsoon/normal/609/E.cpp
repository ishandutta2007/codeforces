#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
typedef long long ll;
typedef pair<int,int> pii;

const int N = 210000;
int n,m,fu[N],a[N],b[N],c[N],idx[N];
ll cost,ans[N];
vector<pii> adj[N];
vector<int> fuc[N];

int fufind(int x) { return fu[x] < 0 ? x : fu[x] = fufind(fu[x]); }

int main() {
  scanf("%d%d",&n,&m);
  REP(i,m) {
    scanf("%d%d%d",&a[i],&b[i],&c[i]); --a[i], --b[i];
    idx[i] = i;
    adj[a[i]].push_back(make_pair(b[i], i));
    adj[b[i]].push_back(make_pair(a[i], i));
  }
  sort(idx, idx+m, [](int i, int j) { return c[i] < c[j]; });

  REP(i,n) { fu[i] = -1; fuc[i].push_back(i); }
  REP(_i,m) {
    int i = idx[_i];
    int A = fufind(a[i]), B = fufind(b[i]);
    if (A != B) {
      cost += c[i];

      if (fuc[A].size() < fuc[B].size()) { swap(A, B); }

      FORE(j,fuc[B]) {
        FORE(v,adj[*j]) if (fufind(v->first) == A) {
          ans[v->second] = c[v->second] - c[i];
        }
        fuc[A].push_back(*j);
      }
      fuc[B].clear();
      fu[B] = A;
    }
  }

  REP(i,m) { printf("%lld\n", cost + ans[i]); }
}