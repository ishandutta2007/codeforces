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

const int N = 110000;
char txt[N];
int czworki[N], siodemki[N];

int main(){
  scanf("%s",txt);
  int n = strlen(txt);
  if (n%2 == 1){
    FORD(i,n-1,0) txt[i+1]=txt[i];
    txt[0] = '0';
    n++;
    txt[n] = 0;
  }
  int a = 0, b = 0;

  REP(i,n){
    czworki[i] = a;
    siodemki[i] = b;
    if (txt[i] == '4') a++;
    if (txt[i] == '7') b++;
  }

  if (a+b == n && a==b){
    puts(txt);
    return 0;
  }

  FORD(i,n-1,0){
    a = czworki[i];
    b = siodemki[i];
    if (a + b != i || a > n/2 || b > n/2) continue;

    int co = -1;
    if (txt[i] < '4' && (a+1) <= n/2) co = 4;
    else if (txt[i] < '7' && (b+1) <= n/2) co = 7;
    if (co == -1) continue;
    REP(j,i) putchar(txt[j]);
    putchar('0'+co);
    if (co == 4) a++;
    else b++;
    REP(j,n-(i+1)){
      if (a+1 <= n/2) putchar('4'), a++;
      else putchar('7');
    }
    puts("");
    return 0;
  }

  REP(i,n/2+1) putchar('4');
  REP(i,n/2+1) putchar('7');
  puts("");
  return 0;
}