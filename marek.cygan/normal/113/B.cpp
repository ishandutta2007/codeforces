#include <cstdio>
#include <cstring>
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

const int N = 4100;
const int P1 = 1000000007;
const int P2 = 123123151; 
char txt[N], s1[N], s2[N];
LL hasz[2][N];
LL potega[2][N];
int poczatek[N], koniec[N];

int pasuje(char *txt1, char *txt2, int d){
  REP(i,d){
    if (*txt1 != *txt2) return 0;
    txt1++; txt2++;
  }
  return 1;
}

vector<pair<LL,LL> > v;

void init_hasze(int n){
  potega[0][0] = potega[1][0] = 1;
  FOR(i,1,N-1){
    potega[0][i] = potega[0][i-1] * P1;
    potega[1][i] = potega[1][i-1] * P2;
  }

  FORD(i,n-1,0){
    hasz[0][i] = hasz[0][i+1] * P1 + txt[i];
    hasz[1][i] = hasz[1][i+1] * P2 + txt[i];
  }
}

inline LL daj_hasz(int id, int a, int d){
  return hasz[id][a]-hasz[id][a+d]*potega[id][d];
}

int main(){
  scanf("%s %s %s",txt,s1,s2);
  int n = strlen(txt);
  init_hasze(n);

  int a = strlen(s1);
  int b = strlen(s2);
  REP(i,n) if (i+a <= n && pasuje(txt+i,s1,a)) poczatek[i] = 1;
  REP(i,n) if (i-b+1 >= 0 && pasuje(txt+i-b+1,s2,b)) koniec[i] = 1;
  int res = 0;
  FOR(d,max(a,b),n){
    v.clear();
    REP(i,n) if (poczatek[i] && koniec[i+d-1]){
      v.PB(MP(daj_hasz(0,i,d), daj_hasz(1,i,d)));
    }
    sort(ALL(v));
    v.erase(unique(ALL(v)), v.end());
    res += SIZE(v);
  }
  printf("%d\n", res);
  return 0;
}