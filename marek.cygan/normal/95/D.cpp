#include <cstring>
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

const int N = 1020;
const int MOD = 1000000007;
int k;

int dobra(char *txt){
  int i = 0;
  int last = -1;
  while (txt[i]){
    if (txt[i] == '4' || txt[i] == '7'){
      if (last != -1 && i-last <= k) return 1;
      last = i;
    }
    i++;
  }
  return 0;
}

int ile[N][N][2]; //na ile sposobow moge uzupelnic d cyframi, przy danej przerwie i jesli jest dobra, moge stawiac wiodace zera
int wszystkie_dobre[N];

void init(){
  FOR(przerwa,0,N-1) ile[0][przerwa][1] = 1;
  FOR(d,1,N-1){
    FOR(przerwa,0,N-1) REP(dobra,2){
      int &x = ile[d][przerwa][dobra];
      x = 0;
      {
        x = (x + 2LL * ile[d-1][0][dobra || (przerwa != N-1 && przerwa < k)]) % MOD;
      }
      {
        x = (x + 8LL * ile[d-1][min(przerwa+1,N-1)][dobra]) % MOD;
      }
    }
  }
  FOR(d,1,N-1){
    wszystkie_dobre[d] = wszystkie_dobre[d-1];
    wszystkie_dobre[d] = (wszystkie_dobre[d] + 2LL * ile[d-1][0][0]) % MOD;
    wszystkie_dobre[d] = (wszystkie_dobre[d] + 7LL * ile[d-1][N-1][0]) % MOD;
  }
}

//ile mniejszych dobrych
int licz(char *txt){
  int n = strlen(txt);
  int res = wszystkie_dobre[n-1];
  int dobra = 0;
  int przerwa = N-1;
  REP(i,n) {
    int last = i == 0 ? 1 : 0;
    for (int cyfra = txt[i]-'0'-1; cyfra >= last; cyfra--){
      int ndobra = dobra;
      int nprzerwa = przerwa;
      if (cyfra == 4 || cyfra == 7){
        ndobra |= (przerwa != N-1 && przerwa < k);
        nprzerwa = 0;
      } else nprzerwa = min(przerwa+1,N-1);
      res = (res + ile[n-i-1][nprzerwa][ndobra]) % MOD;
    }
    if (txt[i] == '4' || txt[i] == '7'){
      dobra |= (przerwa != N-1 && przerwa < k);
      przerwa = 0;
    } else przerwa = min(przerwa+1,N-1);
  }
  return res;
}

char txt[N], txt2[N];

int main(){
  /*
  int foo = 0;
  int ogr;
  scanf("%d %d",&ogr,&k);
  FOR(i,1,ogr){
    sprintf(txt,"%d",i);
    foo += dobra(txt);
  }
  printf("%d\n",foo);
  */
  int testy;
  scanf("%d %d",&testy,&k);
  init();
  while (testy--){
    scanf("%s %s",txt, txt2);
    int res = (licz(txt2) + MOD - licz(txt)) % MOD;
    if (dobra(txt2)) res = (res+1)%MOD;
    printf("%d\n", res);
  }
  return 0;
}