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

const int MOD = 1000000007;
const int N = 1001 * 1001;
LL silnia[N], revsilnia[N];

int NWDR(int a, int b, LL &xp, LL &yp) {
  if (a==0) { xp=0; yp=1; return b; }
  LL x,y;
  int d = NWDR(b%a, a, x, y);
  yp = x;
  xp = y-(b/a)*x;
  return d;
}
int RevMod(int a, int p){
  LL x, y;
  NWDR(a, p, x, y);
  if (x < 0LL) return (p - ((-x) % (LL)p)) % p;
  return x % (LL)p;
}

LL t[1010][1010];

inline LL binom(int a,int b){
  return silnia[a] * revsilnia[b] % MOD * revsilnia[a-b] % MOD;
}

LL potega(LL x, LL n){
  LL res = 1;
  while (n){
    if (n&1) res = res * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return res % MOD;
}

LL pot[N];

int main(){

  silnia[0] = 1 % MOD;
  FOR(i,1,N-1) silnia[i] = (LL)silnia[i-1] * i % MOD;

  REP(i,N) revsilnia[i] = RevMod(silnia[i], MOD);

  int n,m,k;
  cin >> n >> m >> k;

  t[0][0] = 1;

  REP(i,n) FOR(j,0,i) {
    t[i+1][j+1] = (t[i+1][j+1] + t[i][j]) % MOD;
    t[i+1][j] = (t[i+1][j] + (LL)j * t[i][j]) % MOD;
  }

  if (m==1){
    LL res = potega(k, n);
    cout << res << endl;
    return 0;
  }

  FOR(przeciecie,0,n) pot[przeciecie] = potega(przeciecie, n*(m-2));

  LL res = 0;
  FOR(kolory,1,n){
    LL tmp = t[n][kolory] * t[n][kolory] % MOD;
    tmp = tmp * silnia[kolory] % MOD;
    tmp = tmp * silnia[kolory] % MOD;

    FOR(przeciecie,0,kolory) if (przeciecie+2*(kolory-przeciecie) <= k){
      LL konf = tmp;

      konf = konf * binom(k,przeciecie) % MOD;
      konf = konf * binom(k-przeciecie, (kolory-przeciecie)) % MOD;
      konf = konf * binom(k-kolory, (kolory-przeciecie)) % MOD;

      konf = konf * pot[przeciecie];

      res = (res + konf) % MOD;
  //    cout << res << endl;
    }
  }
  cout << res%MOD << endl;
  return 0;
}