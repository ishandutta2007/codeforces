#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
typedef long long ll;
typedef pair<ll,int> plli;

const int N = 210000;
int n,m,x[N],cnt[N],p[N],b[N];
set<plli> frogs, mosq;
ll t[N];

int main() {
  scanf("%d%d",&n,&m);
  REP(i,n) { scanf("%d%lld",&x[i],&t[i]); }

  REP(i,n) {
    set<plli>::iterator it = frogs.lower_bound(make_pair(x[i]+t[i], -1));
    if (it != frogs.end() && x[it->second] <= x[i]) {
      continue;
    } else if (it != frogs.end() && x[i]+t[i] == x[it->second]+t[it->second]) {
      ++it; frogs.erase(prev(it));
    }
    if (it != frogs.begin()) {
      --it;
      while (x[i] <= x[it->second]) {
        if (it == frogs.begin()) { frogs.erase(it); break; }
        else { --it; frogs.erase(next(it)); }
      }
    }

    frogs.insert(make_pair(x[i]+t[i], i));
  }

  REP(i,m) {
    scanf("%d%d",&p[i],&b[i]);

    set<plli>::iterator it = frogs.lower_bound(make_pair(p[i], -1));
    if (it != frogs.end() && x[it->second] <= p[i]) {
      int f = it->second;
      cnt[f]++;
      t[f] += b[i];

      set<plli>::iterator it2 = mosq.lower_bound(make_pair(x[f], -1));
      while (it2 != mosq.end() && p[it2->second] <= x[f]+t[f]) {
        cnt[f]++;
        t[f] += b[it2->second];
        it2++; mosq.erase(prev(it2));
      }

      ++it; frogs.erase(prev(it));
      while (it != frogs.end() && x[it->second]+t[it->second] <= x[f]+t[f]) {
        ++it; frogs.erase(prev(it));
      }

      frogs.insert(make_pair(x[f]+t[f], f));
    } else {
      mosq.insert(make_pair(p[i], i));
    }
  }

  REP(i,n) { printf("%d %lld\n",cnt[i],t[i]); }
}