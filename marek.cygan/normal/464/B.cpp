#include <cassert>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <numeric>
#include <cmath>
using namespace std;

typedef vector <int > VI;
typedef vector < VI > VVI;
typedef long long LL;
typedef vector < LL > VLL;
typedef vector < double > VD;
typedef vector < string > VS;
typedef pair<int,int> PII;
typedef vector <PII> VPII;
typedef istringstream ISS;

#define ALL(x) x.begin(),x.end()
#define REP(i,n) for (int i=0; i<(n); ++i)
#define FOR(var,pocz,koniec) for (int var=(pocz); var<=(koniec); ++var)
#define FORD(var,pocz,koniec) for (int var=(pocz); var>=(koniec); --var)
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define PB push_back
#define PF push_front
#define MP(a,b) make_pair(a,b)
#define ST first
#define ND second
#define SIZE(x) (int)x.size()

VVI v;

VI minuss(VI a, VI b) {
  REP(i,SIZE(a)) a[i] -= b[i];
  return a;
}

LL len(VI x) {
  LL sum = 0;
  REP(i,3) sum += (LL)x[i] * (LL)x[i];
  return sum;
}

LL dot(VI a, VI b) {
  LL res = 0;
  REP(i,3) res += (LL)a[i] * (LL)b[i];
  return res;
}

VVI orig;

int ok(VI x, VI a, VI b, VI c) {
  if (dot(a,b) || dot(a,c) || dot(b,c)) return 0;
  if (len(a) == 0 || len(a) != len(b) || len(b) != len(c) || len(a) != len(c)) return 0;
  VI tab[3] = {a,b,c};
  VVI cand;
  VVI res;
  REP(mask,8) {
    VI y = x;
    REP(i,3) if ((1<<i) & mask) {
      REP(j,3) y[j] += tab[i][j];
    }
    res.PB(y);
    sort(ALL(y));
    cand.PB(y);
  }
  sort(ALL(cand));
  if (cand == v) {
    puts("YES");
    VI used(8,0);
    REP(i,8) {
      int which = -1;
      REP(w,8) if (!used[w]) {
        VI aa = orig[i];
        VI bb = res[w];
        sort(ALL(bb));
        if (aa == bb) {
          which = w;
          break;
        }
      }
      assert(which >= 0);
      used[which] = 1;
      REP(j,3) {
        if (j) printf(" ");
        printf("%d",res[which][j]);
      }
      puts("");
    }
    return 1;
  }
  return 0;
}

int main(){
  REP(i,8) {
    VI x;
    REP(j,3){
      int a;
      scanf("%d",&a);
      x.PB(a);
    }
    sort(ALL(x));
    v.PB(x);
  }
  orig = v;
  sort(ALL(v));
  FOR(i,1,7) FOR(j,i+1,7) FOR(k,j+1,7) {
    VVI vv = v;
    REP(ii,6) {
      REP(jj,6) {
        REP(kk,6) {
          VI a = minuss(vv[i],v[0]);
          VI b = minuss(vv[j],v[0]);
          VI c = minuss(vv[k],v[0]);
          if (ok(vv[0],a,b,c)) {
            return 0;
          }
          next_permutation(ALL(vv[k]));
        }
        next_permutation(ALL(vv[j]));
      }
      next_permutation(ALL(vv[i]));
    }
  }
  puts("NO");
  return 0;
}