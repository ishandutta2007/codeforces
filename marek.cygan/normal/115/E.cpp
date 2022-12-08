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

const int N = 210000;
int koszt[N];
VPII wyscigi[N];

const int BASE = 256 * 1024;
LL drzewo[2*BASE];
LL acc[2*BASE];

void go(int x,int l,int r, int a,int b,LL co){
  if (b < l || a > r) return;
  if (a <= l && r <= b){
    acc[x] += co;
    drzewo[x] += co;
    return;
  }

  acc[2*x] += acc[x]; drzewo[2*x] += acc[x];
  acc[2*x+1] += acc[x]; drzewo[2*x+1] += acc[x];
  acc[x] = 0;

  int m = (l+r)/2;
  go(2*x, l, m, a, b, co);
  go(2*x+1, m+1, r, a, b, co);

  drzewo[x] = max(drzewo[2*x],drzewo[2*x+1]);
}

void dodaj_do_przedzialu(int a, int b, LL co){
  go(1,0,BASE-1,a,b,co);
}

int main(){
  int n,m;
  cin >> n >> m;
  FOR(i,1,n) cin >> koszt[i];
  REP(foo,m){
    int a,b,c;
    cin >> a >> b >> c;
    wyscigi[b].PB(MP(a,c));
  }
  n++;

  FOR(i,1,n){
    LL x = drzewo[1];
    dodaj_do_przedzialu(i,i,x);
    dodaj_do_przedzialu(0,i-1,-koszt[i]);
    FOREACH(it, wyscigi[i]) dodaj_do_przedzialu(0, it->ST-1, it->ND);
  }
  cout << drzewo[1] << endl;
  return 0;
}