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

const int K = 62;
const int N = 101000;
int n;

int a[K][N];
int mam = 0;
int id[K];

void dodaj(const VI &v, int prawa){
  REP(i,n) a[mam][i] = v[i];
  a[mam][n] = prawa;

  REP(k,mam) if (a[mam][id[k]]){
    FOR(i,0,n) a[mam][i] ^= a[k][i];
  }

  int x = -1;
  REP(i,n) if (a[mam][i]){
    x = i;
    break;
  }
  if (x == -1) return;
  id[mam] = x;
  REP(k,mam) if (a[k][x]){
    FOR(i,0,n) a[k][i] ^= a[mam][i];
  }
  mam++;
}

int wynik[N];

void wypisz(){
  REP(i,n) wynik[i] = 0;

  REP(i,mam) wynik[id[i]] = a[i][n];

  REP(i,n){
    if (i) printf(" ");
    printf("%d",wynik[i]+1);
  }
  puts("");
}

LL t[N];

int main(){
  cin >> n;
  REP(i,n) cin >> t[i];

  FORD(bit,60,0){
    int ile = 0;
    VI v(n,0);
    REP(i,n){
      v[i] = ((t[i] >> (LL)bit) & 1LL);
      ile += v[i];
    }

    if (ile%2 == 0 && ile > 0){
      dodaj(v,1);
    }
  }

  FORD(bit,60,0){
    int ile = 0;
    VI v(n,0);
    REP(i,n){
      v[i] = ((t[i] >> (LL)bit) & 1LL);
      ile += v[i];
    }

    if (ile%2) {
      dodaj(v,1);
    }
  }
  wypisz();
  return 0;
}