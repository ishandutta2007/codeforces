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

const int N = 310 * 1001;
const int INF = 1001LL * 1001 * 1001;
LL sum_pairs[N];
int max_top[N];
char wynik[N];

LL licz(VPII _single, vector<pair<PII,PII> > pairs, int w, LL goal) {
  LL res = 2LL * (LL)N * INF;

  VPII sure_single;
  LL sum_single = 0;

  multiset<PII> single;
  FOREACH(it, _single) single.insert(*it);

  sort(ALL(pairs));

  int n = SIZE(pairs);
  REP(i,n) {
    sum_pairs[i] = pairs[i].ST.ST + (i == 0 ? 0 : sum_pairs[i-1]);
    max_top[i] = max((i == 0 ? 0 : max_top[i-1]), pairs[i].ND.ND-pairs[i].ND.ST);
  }

  FORD(i,n-1,0) {
    while (!single.empty() && SIZE(sure_single) + 2 * (i+1) < w) {
      PII p = *single.begin();
      single.erase(single.begin());
      sure_single.PB(p);
      sum_single += p.ST;
    }
    if (2*(i+1) + SIZE(sure_single) >= w && sum_single + sum_pairs[i] < res) {
      res = sum_single + sum_pairs[i];
      if (res == goal) {
        //TODO: odtworz wynik
        cout << res << endl;
        FOREACH(it, sure_single) wynik[it->ND]++;
        FOR(j,0,i) wynik[pairs[j].ST.ND] += 2;
        puts(wynik);
        return res;
      }
    }


    while (!single.empty() && SIZE(sure_single) + 2 * i + 1 < w) {
      PII p = *single.begin();
      single.erase(single.begin());
      sure_single.PB(p);
      sum_single += p.ST;
    }
    if (2*i+1 + SIZE(sure_single) >= w && sum_single + sum_pairs[i] - max_top[i] < res) {
      res = sum_single + sum_pairs[i] - max_top[i];
      if (res == goal) {
        //TODO: odtworz wynik
        cout << res << endl;
        FOREACH(it, sure_single) wynik[it->ND]++;
        FOR(j,0,i) wynik[pairs[j].ST.ND] += 2;
        FOR(j,0,i) if (pairs[j].ND.ND - pairs[j].ND.ST == max_top[i]) {
          wynik[pairs[j].ST.ND]--;
          break;
        }
        puts(wynik);
        return res;
      }
    }

    single.insert(MP(pairs[i].ND.ST,pairs[i].ST.ND));
  }

  while (!single.empty() && SIZE(sure_single) < w) {
    PII p = *single.begin();
    single.erase(single.begin());
    sure_single.PB(p);
    sum_single += p.ST;
  }
  if (SIZE(sure_single) >= w && sum_single < res) {
    res = sum_single;
    if (res == goal) {
      //TODO: odtworz wynik
      cout << res << endl;
      FOREACH(it, sure_single) wynik[it->ND]++;
      puts(wynik);
      return res;
    }
  }
  return res;
}

int main() {
  int n, w;
  scanf("%d %d", &n, &w);
  VPII single;
  vector<pair<PII,PII> > pairs;
  REP(i, n) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (b-a >= a) {
      single.PB(MP(a,i));
      single.PB(MP(b-a,i));
    } else {
      pairs.PB(MP(MP(b,i), MP(a,b)));
    }
  }
  REP(i,n) wynik[i] = '0';

  LL res = licz(single, pairs, w, -1);
  licz(single, pairs, w, res);
  return 0;
}