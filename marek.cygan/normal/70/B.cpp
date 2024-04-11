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

const int N = 11000;
char txt[N];
VI zdania;
int t[N];

int main(){
  int d;  
  fgets(txt,N-1,stdin);
  sscanf(txt,"%d",&d);
  fgets(txt,N-1,stdin);
  int last = -2;
  for (int i = 0; txt[i] && txt[i] != 10 && txt[i] != 13; ++i){
    if (txt[i] == '.' || txt[i] == '?' || txt[i] == '!'){
      zdania.PB(i-last-1);
      last = i;
    } 
  }
  //FOREACH(it, zdania) printf("%d ",*it); puts("");
  t[0] = 0;
  int n = SIZE(zdania);
  FOR(i,1,n){
    t[i] = N;
    int mam = -1;
    FORD(j,i-1,0){
      mam += 1 + zdania[j];
      if (mam <= d){
        t[i] = min(t[i], t[j]+1);
      } else break;
    }
  }
  if (t[n] >= N) puts("Impossible");
  else printf("%d\n", t[n]);
  return 0;
}