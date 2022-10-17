#include <cstdio>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;
typedef pair<int,int> pii;
typedef tree<int,null_type,less<int>,rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;

const int N = 510000;
int n,m,q,cnt[N],idx[N],q_idx[N],ans[N];
ll pref[N];
pii query[N];

int main() {
  scanf("%d%d%d",&n,&m,&q);
  REP(i,n) {
    int a; scanf("%d",&a); cnt[--a]++;
  }
  REP(i,m) { idx[i] = i; }
  sort(idx, idx+m, [](int i, int j) { return cnt[i] < cnt[j]; });
  pref[0] = 0;
  REP(i,m) {
    pref[i+1] = pref[i] + ll(i+1)*(cnt[idx[i+1]] - cnt[idx[i]]);
  }

  REP(i,q) {
    ll a; scanf("%lld",&a); a -= n+1;
    int pos = upper_bound(pref, pref+m, a) - pref;
    a -= pref[pos-1];
    a %= pos;

    query[i] = make_pair(pos, a);
    q_idx[i] = i;
  }

  sort(q_idx, q_idx+q, [](int i, int j) { return query[i] < query[j]; });
  ordered_set s;
  REP(i,q) {
    int pos,a; tie(pos, a) = query[q_idx[i]];
    while (s.size() < pos) {
      s.insert(idx[s.size()]);
    }
    ans[q_idx[i]] = *s.find_by_order(a);
  }
  REP(i,q) printf("%d\n",ans[i]+1);
}