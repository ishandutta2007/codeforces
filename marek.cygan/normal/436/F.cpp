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

const int N = 112 * 1000;
const int BSIZE = 100;
const int BNUM = 1002;

LL best_gain[N];
int best_price[N];
int when_clean[N];
int bigger[N]; //how many bigger prices are than all in this block
int num_guys[N];

void recalc(int b) {
  LL gcur = 0;
  int valid = N;
  int l = b * BSIZE;
  int r = l + BSIZE-1;
  int p = l;

  int cust = bigger[b];
  FORD(i,r,l) {
    cust += num_guys[i];
    if ((LL)cust * i > gcur) {
      gcur = (LL)cust * i; 
      p = i;
    }
  }
  cust = bigger[b];
  FORD(i,r,p+1) {
    cust += num_guys[i];
    valid = (int)min((LL)valid, (gcur - (LL)cust * i) / (i-p));
  }
  //TODO update when_clean
  best_gain[b] = gcur;
  best_price[b] = p;
  //printf("valid = %d\n", valid);
  when_clean[b] = max(0, valid-2);
}

void dodaj(int x) {
  int b = x / BSIZE;
  num_guys[x]++;
  recalc(b);
  REP(i,b) {
    bigger[i]++;
    if (when_clean[i] == 0) recalc(i);
    else {
      when_clean[i]--;
      best_gain[i] += best_price[i];
    }
  }
}

pair<LL,int> find_max() {
  LL res = 0;
  int p = 0;
  REP(i, BNUM) if (best_gain[i] > res) {
    res = best_gain[i];
    p = best_price[i];
  }
  return MP(res, p);
}

void init() {
  REP(i, BNUM) {
    best_gain[i] = best_price[i] = 0;
    when_clean[i] = N;
  }
}

int main(){
  init();

  int n, w;
  scanf("%d %d",&n,&w);
  VPII v;
  int mb = 0;
  REP(i,n) {
    int a, b;
    scanf("%d %d",&a,&b);
    mb = max(mb, b);
    v.PB(MP(b,a));
  }
  sort(ALL(v));

  int pos = 0;
  FOR(c,0,mb+1) {
    while (pos < SIZE(v) && v[pos].ST < c) {
      dodaj(v[pos].ND);
      pos++;
    }
    pair<LL,int> p = find_max();
    cout << (p.ST + (LL)c * w * (SIZE(v) - pos)) << " " << p.ND << endl;
 //   cout << (p.ST + (LL)c * w * (SIZE(v) - pos)) << endl;
  }
  return 0;
}