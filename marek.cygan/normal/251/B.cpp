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

const int N = 110;

int p[N];
int prev[N];
int cel[N];
int t[N],t2[N];

int rowne(int* a,int* b, int n){
  REP(i,n) if (a[i] != b[i]) return 0;
  return 1;
}

int n,k;

int main(){
  scanf("%d %d",&n,&k);
  REP(i,n) scanf("%d",p+i), p[i]--;
  REP(i,n) scanf("%d",cel+i), cel[i]--;

  REP(i,n) t[i] = i;
  if (rowne(t,cel,n)) puts("NO");
  else {
    int d1 = N;
    int d2 = N;

    REP(i,n) t[i] = i;
    REP(foo,k){
      REP(i,n) t2[i] = t[p[i]];
      REP(i,n) t[i] = t2[i];
      if (rowne(t,cel,n)) {
        d1 = foo+1;
        break;
      }
    }

    REP(i,n) prev[p[i]] = i;

    REP(i,n) t[i] = i;
    REP(foo,k){
      REP(i,n) t2[i] = t[prev[i]];
      REP(i,n) t[i] = t2[i];
      if (rowne(t,cel,n)) {
        d2 = foo+1;
        break;
      }
    }

    /*
    REP(i,n) t[i] = i;
    REP(i,n) t2[i] = t[p[i]];
    REP(i,n) t[i] = t2[i];
    REP(i,n) t2[i]= t[prev[i]];
    REP(i,n) printf("%d ",t2[i]); puts("");

    printf("%d %d\n", d1, d2);
    */

    if (d1 == 1 && d2 == 1){
      if (k == 1) puts("YES");
      else puts("NO");
    } else {
      if (d1 <= k && d1 % 2 == k % 2 || d2 <= k && d2 % 2 == k % 2) puts("YES");
      else puts("NO");
    }
  }
  return 0;
}