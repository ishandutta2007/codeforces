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

const int N = 110 * 1010;
char txt[N];
char pom[N];
LL t[10];
LL dlug[10];
vector<pair<int,string> > v;

const LL MOD = 1000000007;

LL pot10(LL n) {
  LL res = 1;
  LL acc = 10;
  while (n > 0) {
    if (n & 1) res = (res * acc) % (MOD);
    acc = (acc * acc) % (MOD);
    n >>= 1;
  }
  return res;
}

int main(){
  int n;
  scanf("%s %d", txt, &n);
  v.reserve(n);
  REP(i,n) {
    scanf("%s",pom);
    v.PB(MP(pom[0]-'0',string(pom+3)));
  }
  REP(i,10){
    t[i] = i;
    dlug[i] = 1;
  }

  FORD(j,n-1,0) {
    LL x = 0;
    LL dd = 0;
    REP(i,SIZE(v[j].ND)){
      int c = v[j].ND[i]-'0';
      x = (x * pot10(dlug[c]) + t[c]) % MOD;
      dd = (dd + dlug[c]) % (MOD-1);
    }
    t[v[j].ST] = x;
    dlug[v[j].ST] = dd;
  }

  int pos = 0;
  LL res = 0;
  while (txt[pos]) {
    int c = txt[pos]-'0';
    res = (res * pot10(dlug[c]) + t[c]) % MOD;
    pos++;
  }
  cout << res << endl;
  return 0;
}