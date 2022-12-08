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

const int N = 1100;
int t[N];

const string no = "No";
const string yes = "Yes";

void wypisz(VI v){
  REP(i,SIZE(v)){
    if (i) printf(" ");
    printf("%d", v[i]+1);
  }
  puts("");
}

void jedynka(int ktory, int n){
  printf("%s\n", yes.c_str());
  VI v;
  v.PB(ktory);
  REP(i,n) if (i != ktory) REP(j,2*t[i]) v.PB(i);
  v.PB(ktory);
  wypisz(v);
}

int main(){
  int n,w;
  scanf("%d %d",&n,&w);
  int suma = 0;
  REP(i,n){
    scanf("%d",t+i);
    suma += t[i];
  }

  if (n==1){
    if (w != t[0]) printf("%s\n", no.c_str());
    else {
      printf("%s\n", yes.c_str());
      VI v(2*t[0], 0);
      wypisz(v);
    }
  } else {
    if (w <= 0 || w > suma){
      printf("%s\n", no.c_str());
      return 0;
    } else if (w==1) {
      int ktory = -1;
      REP(i,n) if (t[i] == 1) ktory = i;
      if (ktory == -1){
        printf("%s\n", no.c_str());
        return 0;
      } else {
        jedynka(ktory, n);
      }
    } else {
      // 2 <= w <= suma
      if (w == suma){
        VI v;
        REP(i,n) REP(j,2*t[i]) v.PB(i);
        printf("%s\n", yes.c_str());
        wypisz(v);
        return 0;
      }

      VI v;
      while (n > 2 && w > 2){
        v.PB(n-1); v.PB(n-1);
        t[n-1]--; w--;
        if (t[n-1] == 0) n--;
      }
      if (n == 2 && w > 2){
        while (w > 2){
          REP(i,2) if (t[i] > 1){
            w--;
            v.PB(i); v.PB(i);
            t[i]--;
            break;
          }
        }
      }
      assert(n >= 2 && w == 2);
      int ktory = -1;
      REP(i,n) if (t[i] > 1){
        ktory = i;
      }
      if (ktory == -1){
        //same jedynki
        v.PB(0); v.PB(0);
        v.PB(1);
        FOR(i,2,n-1) REP(foo,2) v.PB(i);
        v.PB(1);

        printf("%s\n", yes.c_str());
        wypisz(v);
      } else {
        int drugi = (ktory != 0) ? 0 : 1;
        v.PB(ktory);
        REP(i,n) if (i != ktory && i != drugi) REP(j,2*t[i]) v.PB(i);
        REP(j,2*(t[drugi]-1)) v.PB(drugi);
        v.PB(ktory);
        v.PB(drugi);
        REP(j,2*(t[ktory]-1)) v.PB(ktory);
        v.PB(drugi);
        printf("%s\n", yes.c_str());
        wypisz(v);
      }
    }
  }
  return 0;
}