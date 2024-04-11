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

#define MAX 100100

vector<int> duzo;
int ile[MAX],a[MAX];
bool czyduzo[MAX];
int res[MAX];
int kr[MAX],kr2[MAX];
int n;
int sq;
struct zap{
  int a,b;
  int nr;
  void pob(){
    cin >> a >> b;
    a--;
  }
}t[MAX];
void dod(int nr){
  int kt = a[nr];
  debug("dod",kt);
  ile[kt]++;
  if(!czyduzo[kt]){
    kr[ile[kt]-1]--;  
    kr[ile[kt]]++;
  }
}
void us(int nr){
  int kt = a[nr];
  debug("us",kt);
  ile[kt]--;
  if(!czyduzo[kt]){
    kr[ile[kt]]++;
    kr[ile[kt]+1]--;
  }
}

// int log[MAX];
// vector<PII> t[20];
int licz(){
  map<int,int> huff;
  for(int i=1;i < sq;i++){
    kr2[i] = kr[i];
  }
  auto dod = [&](int a,int b){
    if(a < sq)
      kr2[a] += b;
    else
      huff[a] += b;
  };
  for(int i:duzo){
    if(ile[i])dod(ile[i],1);
  }
  int ind = 0;
  int mam = -1;
  int res = 0;
  while(!huff.empty() || ind != sq){
    int w,k;
    if(ind < sq){
      ind++;
      if(kr2[ind]){
        w = ind;
        k = kr2[ind];
      }else{
        continue;
      }
    }else{
      auto x = huff.begin();
      tie(w,k) = *x;
      huff.erase(x);
    }
    if(mam != -1){
      res += mam + w;
      dod(mam+w,1);
      k--;
    }
    if(k >= 2){
      res += k/2*2*w;
      dod(w*2,k/2);
      k&=1;
    }
    if(k)
      mam = w;
    else
      mam = -1;
  }
  return res;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  R(i,n){
    cin >> a[i];
    ile[a[i]]++;
  }
  sq = 1300;
  debug(sq);
  R(i,MAX){
    if(ile[i] >= sq){
      czyduzo[i] = 1;
      duzo.PB(i);
    }else{
      kr[0]++;
    }
    ile[i] = 0;
  }
  int q;
  cin >> q;
  R(i,q){
    t[i].pob();
    t[i].nr = i;
  }
  sort(t,t+q,[](zap a,zap b){
    int ba = a.a / sq;
    int bb = b.a / sq;
    if(ba != bb){
      return ba < bb;
    }
    return !!((ba&1) ^ (a.b < b.b));
  });
  int x = 0,y = 0;
  R(i,q){
    while(x < t[i].a){
      us(x);
      x++;
    }
    while(x > t[i].a){
      x--;
      dod(x);
    }
    while(y < t[i].b){
      dod(y);
      y++;
    }
    while(y > t[i].b){
      y--;
      us(y);
    }
    debug("licze",t[i].nr,x,y);
    res[t[i].nr] = licz();
  }
  R(i,q){
    cout << res[i] << "\n";
  }
}