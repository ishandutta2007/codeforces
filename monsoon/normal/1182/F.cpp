#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

template<class T>
inline void minimize(T& a, const T& b) { if (b < a) a = b; }

const int SQ = 32000;
int _,a,b,p,q;
pair<int,int> tab[SQ],ans;


int main() {
  scanf("%d",&_);
  while (_-->0) {
    scanf("%d%d%d%d",&a,&b,&p,&q);
    int B = sqrt(b+1-a);
    REP(i,B) {
      tab[i] = make_pair(ll(2*p)*(i+a) % (2*q), i+a);
    }
    sort(tab,tab+B);
    // remove duplicates (!)
    int NB=0;
    REP(i,B) {
      if (!i || tab[i].first != tab[NB-1].first)
        tab[NB++] = tab[i];
    }

    ans = make_pair(2*q, -1);
    REP(i,(b+1-a + B-1)/B) {
      int beg = min(i*B, b-a+1 - B);
      // cand = (q - 2*p*beg) % (2*q)
      int cand = ll(2*p)*beg % (2*q);
      cand = (ll(3)*q - cand) % (2*q);
      int pos = lower_bound(tab,tab+NB,make_pair(cand,-1)) - tab;
      int idx[] = { pos % NB, (pos + NB-1) % NB };
      REP(j,2) {
        int elem = tab[idx[j]].first;
        int dist = abs(cand - elem);
        dist = min(dist, 2*q - dist);
        int pos = tab[idx[j]].second + beg;
        minimize(ans, make_pair(dist, pos));
      }
    }
    printf("%d\n",ans.second);
  }
}