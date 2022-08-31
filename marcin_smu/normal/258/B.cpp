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

template<class C> void mini(C& _a4, C _b4) { _a4 = min(_a4, _b4); }
template<class C> void maxi(C& _a4, C _b4) { _a4 = max(_a4, _b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream& operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto& vv : V) os << vv << ","; os << "]";
  return os;
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int P = 1e9 + 7;
int il[10];
int dp[20][20];
int odw(int a){
  int w = P-2;
  int r = 1;
  while(w){
    if(w&1)
      r = r * a % P;
    w/=2;
    a = a * a % P;
  }
  return r;
}
int licz(int a,int k){
  int res = 1;
  R(i,k){
    res *= (a - i);
    res %= P;
  }
  R(i,k){
    res *= odw(i+1);
    res %= P;
  }
  return res;
}
int p10[20];
int p8[20];
int p2[20];
int po[20][20];
vector<int> cyf;
void xx(int a,int dl){
  int ak = 0;
  while(p10[dl]*ak < a){
    
  }
}
int lucky(int a){
  return a == 4 || a == 7;
}
void dod(int add,int dl){
  debug(add,dl);
  R(i,dl+1){
    debug(add+i, p2[i] * p8[dl-i] * po[dl][i]);
    il[add+i] += p2[i] * p8[dl-i] * po[dl][i];
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int m;
  cin >> m;
  p2[0] = 1;
  p8[0] = 1;
  R(i,19){
    p2[i+1] = p2[i] * 2;
    p8[i+1] = p8[i] * 8;
  }
  R(i,20)R(j,i+1){
    if(j == 0)
      po[i][j] = 1;
    else
      po[i][j] = (po[i-1][j] + po[i-1][j-1]);
  }
  while(m){
    cyf.PB(m%10);
    m/=10;
  }
  int dl = SZ(cyf);
  int ak = 0;
  R(i,SZ(cyf)) if(cyf[i] == 4 || cyf[i] == 7) ak++;
  m = 0;
  debug(ak);
  il[ak]++;
  il[0]--;
  debug(il[ak],ak);
  R(i,dl){
    m *= 10;
    m += cyf[i];
    if(cyf[i] == 4 || cyf[i] == 7) ak--;
    R(j,10){
      if(j < cyf[i]){
        dod(ak + lucky(j),i);
      }
    }
    
    debug(il[0]);
  }
//   il[0] = m;
//   for(int dl = 1;dl < 10;dl++){
//     R(mb2,1<<dl){
//       int pom = 0;
//       int mb = mb2;
//       R(i,dl){
//         pom*=10;
//         if(mb&1){
//           pom+=4;
//         }else{
//           pom+=7;
//         }
//         mb/=2;
//       }
//       debug(pom);
//       if(pom <= m){
//         il[0]--;
//         il[dl]++;
//       }
//     }
//   }
  R(i,9){
    debug(i,il[i]);
  }
  dp[0][0] = 1;
  R(i,10){
    for(int j = 6; j > 0; j--){
      R(k,j+1){
        if(k == 0)continue;
        int pom = licz(il[i], k);
        R(l,10){
          if(l < k*i)continue;
          dp[j][l] += pom * dp[j-k][l-k*i]; 
          dp[j][l] %= P;
        }
      }
    }
  }
  int res = 0;
  R(i,10){
    R(j,i){
      res += il[i] * dp[6][j] % P;
    }
  }
  debug(res);
  int POM = licz(il[0],6) * 2 % P;
  debug(POM);
  int POM2 = licz(il[0],6) * (il[1] + il[2]) % P + licz(il[0],5) * il[2] * il[1] % P;
  debug(POM2 % P);
  R(i,6){
    res *= i+1;
    res %= P;
  }
  cout << res % P << endl;
}