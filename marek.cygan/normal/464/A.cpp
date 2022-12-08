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

const int N = 1010 * 100;
char txt[N];

int main(){
  int n, p;
  scanf("%d %d %s",&n,&p,txt);
  if (p == 1) puts("NO");
  else if (p == 2) {
    if (n == 1) {
      if (txt[0] == 'a') puts("b");
      else puts("NO");
    } else {
      assert(n == 2);
      if (txt[0] == 'a') puts("ba");
      else puts("NO");
    }
  } else {
    FORD(i,n-1,0) if (txt[i] - 'a' != p-1) {
      FOR(c,txt[i]+1,'a'+p-1) if ((i == 0 || txt[i-1] != c) && (i <= 1 || txt[i-2] != c)){
        txt[i] = c;
        FOR(j,i+1,n-1) {
          c = 'a';
          while ((j >= 1 && txt[j-1] == c) || (j >= 2 && txt[j-2] == c)) c++;
          txt[j] = c;
        }
        puts(txt);
        return 0;
      }
    }
    puts("NO");
  }
  return 0;
}