#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int P = 1e9 + 7;
const int n = 17;
//const int n = 2;
const int MAX = 1 << n;
const int MASK = MAX - 1;
int il[MAX],fsc[MAX],fc2[MAX],f[MAX];
int N;
int add(int a,int b){
  a += b;
  if(a >= P)
    a-=P;
  return a;
}
int mul(int a,int b){
  return a * b % P;
}
void sub(int &a,int b){
  a -= b;
  if(a < 0){
    a += P;
  }
}
void dofsc(int* x){
  R(i,n)R(mb, 1 << n)if((mb >> i) & 1){
    x[mb] = add(x[mb], x[mb - (1 << i)]);
  }
}
void invfsc(int *x){
  R(i,n)R(mb, 1 << n)if((mb >> i) & 1){
    sub(x[mb], x[mb - (1 << i)]);
  }
}
void debugt(int* x){
//   R(i,1 << n){
//     cerr << x[i] << " ";
//   }
//   cerr << "\n";
//   
}
void rob(int *x){
  debug(":P");
  debugt(x);
  R(i,1 << n){
    x[i] = mul(x[i], f[i]);
  }
  debugt(x);
 
  R(i,1 << (n - 1)){
    swap(x[i], x[MASK^i]);
  }
  debugt(x);
  dofsc(x);
  debug("tu:");
  debugt(x);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  f[0] = 0;
  f[1] = 1;
  for(int i = 2; i < MAX; i++){
    f[i] = add (f[i-1], f[i-2]);
  }
  
  cin >> N;
  R(i,N){
    int pom;
    cin >> pom;
    il[pom]++;
    fc2[pom]++;
  }

  //dofsc(fsc);
  debugt(il);
  R(mb,1 << n)if(mb){
    int pom = mb;
    pom -= pom & -pom;
    debug(mb,pom,il[pom]);;
    for(int mb2 = pom; ;mb2 = (mb2 - 1) & pom){
      fsc[mb] += il[mb2] * il[mb^mb2];
      if(mb2 == 0)break;
    }
    fsc[mb] *= 2;
    fsc[mb] %= P;
  }
  //invfsc(fsc);
  debug("??");
  debugt(fsc);
  
  debugt(fc2);
  for(int i = n-1; i >= 0; i--)R(mb, 1 << n){
    if((mb >> i) & 1){
      int pom = add(fc2[mb], fc2[mb ^ (1 << i)]);
      sub(fc2[mb], fc2[mb ^ (1 << i)]);
      fc2[mb] = P - fc2[mb];
      fc2[mb ^ (1 << i)] = pom;
    }
  }
  
  debugt(fc2);
  
  R(i,1 << n){
    fc2[i] = mul(fc2[i], fc2[i]);
  }
  debugt(fc2);
  
  const int xxx = (P+1)/2;
  R(i,n){
    R(mb, 1 << n){
      if((mb >> i) & 1){
        int pom = mul(xxx, add(fc2[mb], fc2[mb ^ (1 << i)]));
        sub(fc2[mb ^ (1 << i)], fc2[mb]);
       //debug(fc2[mb ^ (1 << i)]);
        fc2[mb] = mul(fc2[mb ^ (1 << i)], xxx);
        fc2[mb ^ (1 << i)] = pom;
      }
    }
//     R(mb, 1 << n){
//     
//       cerr << fc2[mb] << " ";
//     }
//     cerr << "\n";
  }
  debugt(fc2);
  
//   R(i,n)R(mb, 1 << n){
//     sub(fc2[mb], fc2[mb ^ (1 << i)]);
//   }
  
  rob(fsc);
  rob(il);
  rob(fc2);
  
  
  R(i,1 << n){
    fsc[i] = mul(fsc[i], mul(fc2[i], il[i]));
  }
  invfsc(fsc);
  debugt(fsc);
  int res = 0;
  R(i,n){
    res = add(res, fsc[MASK - (1 << i)]);
  }
  cout << res << "\n";
}