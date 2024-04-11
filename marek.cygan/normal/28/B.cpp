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

const int N = 510;

int perm[N],skok[N];
int n;
int fu[N];

int between(int a,int b,int c){
  return a >= b && a <= c;
}

int fufind(int x){
  return fu[x] < 0 ? x : fu[x] = fufind(fu[x]);
}

void lacz(int a,int b){
  if (!between(a,0,n-1)) return;
  if (!between(b,0,n-1)) return;
  a=fufind(a);
  b=fufind(b);
  if (a!=b){
    fu[b] += fu[a];
    fu[a] = b;
  }
}

int main(){
  scanf("%d",&n);
  REP(i,n) scanf("%d",perm+i),perm[i]--;
  REP(i,n) scanf("%d",skok+i);
  REP(i,n) fu[i]=-1;
  REP(i,n) lacz(i,i-skok[i]),lacz(i,i+skok[i]);
  REP(i,n) if (fufind(i) != fufind(perm[i])){
    puts("NO");
    return 0;
  }
  puts("YES");
  return 0;
}