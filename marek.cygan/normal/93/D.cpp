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
const int WYMIAR=17;
int mod = MOD;

struct M{
  int t[WYMIAR][WYMIAR];
  M() {REP(i,WYMIAR) REP(j,WYMIAR) t[i][j]=0; REP(i,WYMIAR) t[i][i]=1;}
};

M operator *(const M &a, const M &b){
  M res;
  REP(i,WYMIAR) REP(j,WYMIAR){
    LL acc=0;
    REP(k,WYMIAR) acc+=(LL)a.t[i][k]*b.t[k][j]%mod;
    res.t[i][j]=acc%mod;
  }
  return res;
}

M potega(M x,LL n){
  M res,acc=x;
  REP(i,WYMIAR) res.t[i][i]=1;
  while (n){
    if (n&1) res=res*acc;
    acc=acc*acc;
    n/=2;
  }
  return res;
}

PII rozloz(int x){
  return MP(x/4, x%4);
}

int zabron(int a,int b){
  if (a > b) return zabron(b,a);
  if (a==b) return 1;
  if (a==0 && b==3) return 1;
  if (a==1 && b==2) return 1;
  return 0;
}

int dobra_para(int aa,int bb){
  PII a=rozloz(aa);
  PII b=rozloz(bb);
  if (a.ND != b.ST) return 0;
  if (zabron(b.ST,b.ND)) return 0;
  if (a.ST == 1 && b.ST == 0 && b.ND == 2) return 0;
  if (a.ST == 2 && b.ST == 0 && b.ND == 1) return 0;
  return 1;
}

int licz(int n){
  if (n==0) return 0;
  if (n==1) return 4;
  M m;
  REP(i,16) REP(j,16) m.t[i][j] = dobra_para(i,j);
  REP(i,17) m.t[i][16] = 1;

  int stan[17];
  stan[16]=4;
  REP(i,16){
    PII p = rozloz(i);
    stan[i] = !zabron(p.ST,p.ND);
  }
  M tmp=potega(m,n-1);
  int acc = 0;
  REP(i,17) acc = (acc + (LL)stan[i] * tmp.t[i][16]) % MOD;
  return acc % MOD;
}

int licz2(int n){
  if (n==0) return 0;
  if (n==1) return 4;
  int res = licz(n);
  int palindromy = licz((n+1)/2);
  int niepal = ((MOD + res - palindromy) % MOD) * (LL)500000004 % MOD;
//  printf("n=%d wszystkie=%d pal=%d\n",n,res,palindromy);
  return (palindromy+niepal)%MOD;
}

int main(){
  int l,r;
  scanf("%d %d",&l,&r);
  printf("%d\n",(licz2(r)+MOD-licz2(l-1))%MOD);
  return 0;
}