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
#include <cassert>
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

const int N = 210;

char imie[N], txt[N];
int pasuje[N];
int rozmiar_imienia;

int t[N][N];
char t_lit[N][N];
PII t_stan[N][N];
int przejscie[N][N];
int n,k;

int licz(int pozycja, int prefiks){
  assert(prefiks < rozmiar_imienia);
  if (t[pozycja][prefiks] >= 0) return t[pozycja][prefiks];
  int &res = t[pozycja][prefiks];
  if (pozycja+prefiks==n){
    res = 1;
  } else {
    res = 0;
    REP(lit,k){
      int npoz, dlug;
      if (imie[prefiks]-'a' == lit){
        if (prefiks+1==rozmiar_imienia){
          if (pasuje[pozycja]==0) continue;
          dlug = przejscie[prefiks][lit];
          npoz = pozycja+prefiks+1-dlug;
          int zle = 0;
          FOR(i,pozycja+1,npoz-1) if (pasuje[i]==1){
            zle=1;
            break;
          }
          if (zle) continue;
        } else {
          npoz = pozycja;
          dlug = prefiks+1;
        }
      } else {
        dlug = przejscie[prefiks][lit];
        npoz = pozycja+prefiks+1-dlug;
        int zle = 0;
        FOR(i,pozycja,npoz-1) if (pasuje[i]==1){
          zle=1;
          break;
        }
        if (zle) continue;
      }
      if (licz(npoz,dlug)){
        res = 1;
        t_lit[pozycja][prefiks] = lit+'a';
        t_stan[pozycja][prefiks] = MP(npoz,dlug);
        break;
      }
    }
  }
  return res;
}

void licz_przejscia(){
  //licze wlasciwe najdluzsze sufiksy, ktore sa prefiksem imienia
  REP(i,rozmiar_imienia) REP(lit,k){
    string s = "";
    REP(j,i) s += imie[j];
    s += 'a'+lit;
    int dobry;
    do{
      s = s.substr(1);
      dobry = 1;
      REP(j,SIZE(s)) if (s[j] != imie[j]){
        dobry = 0;
        break;
      }
    } while (!dobry);
    przejscie[i][lit] = SIZE(s);
  }
}

void odzyskaj_wynik(){
  int pozycja = 0, prefiks = 0;
  string s;
  while (SIZE(s) < n){
    assert(t[pozycja][prefiks] == 1);
    s += t_lit[pozycja][prefiks];
    PII p = t_stan[pozycja][prefiks];
    pozycja = p.ST;
    prefiks = p.ND;
  }
  printf("%s\n", s.c_str());
}

int main(){
  scanf("%d %d",&n,&k);
  scanf("%s",imie);
  rozmiar_imienia = strlen(imie);
  licz_przejscia();
  scanf("%s",txt);
  for (int i = 0; txt[i]; ++i) if (txt[i]=='1') pasuje[i] = 1;
  FOR(i,0,n) FOR(j,0,n) t[i][j] = -1;
  if (!licz(0,0)) puts("No solution");
  else odzyskaj_wynik();
  return 0;
}