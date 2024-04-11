#pragma GCC optimize("O3")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// gp_hash_table<int, int> mapka;

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
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
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

void xx(string &a){
  for(char& el:a){
    el -= 'a';
  }
}
struct Sol{
  int k;
  string a,b,s;
  vector<int> p;
  int uz;
  int n;
  inline bool czywolne(int x){
    return ((uz >> x)&1) == 1;
  }
  inline void zajmnij(int x){
    uz ^= 1 << x;
  }
  
  bool licza(int id){
    if(id == n)return 1;
    if(p[s[id]] != -1){
      if(p[s[id]] > a[id])return 1;
      if(p[s[id]] == a[id])return licza(id + 1);
      return 0;
    }
    
    if(uz >> (a[id] + 1)){
      for(int i = a[id] + 1; ; i++){
        if(czywolne(i)){
          p[s[id]] = i;
          zajmnij(i);
          return 1;
        }
      }
    }
    if(czywolne(a[id])){
      p[s[id]] = a[id];
      zajmnij(a[id]);
      if(licza(id+1)){
        return 1;
      }
      p[s[id]] = -1;
      zajmnij(a[id]);
    }
    return 0;
  }
  
  bool liczb(int id){
    if(id == n)return 1;
    if(p[s[id]] != -1){
      if(p[s[id]] < b[id])return 1;
      if(p[s[id]] == b[id])return liczb(id + 1);
      return 0;
    }
    
    if(uz & ((1 << b[id])-1)){
      for(int i = 0; i < b[id]; i++){
        if(czywolne(i)){
          p[s[id]] = i;
          zajmnij(i);
          return 1;
        }
      }
      assert(0);
    }
    if(czywolne(b[id])){
      p[s[id]] = b[id];
      zajmnij(b[id]);
      if(liczb(id+1)){
        return 1;
      }
    }
    return 0;
  }
  
  bool liczoba(int id){
    if(id == n)return 1;
    if(a[id] > b[id])return 0;
    if(a[id] == b[id]){
      int co = s[id];
      int naco = a[id];
      debug(co, naco);
      if(p[co] == naco){
        return liczoba(id+1);
      }else{
        if(p[co] == -1 && czywolne(naco)){
          p[co] = naco;
          zajmnij(naco);
          return liczoba(id + 1);
        }
      }
    }else{
      if(p[s[id]] != -1){
        if(a[id] < p[s[id]] && p[s[id]] < b[id])return 1;
        if(a[id] == p[s[id]])return licza(id + 1);
        if(p[s[id]] == b[id])return liczb(id + 1);
        return 0;
      }
      
      if((uz >> (a[id] + 1)) & ((1 << (b[id] - a[id] - 1))-1)){
        for(int i = a[id] + 1; i < b[id]; i++){
          if(czywolne(i)){
            p[s[id]] = i;
            zajmnij(i);
            return 1;
          }
        }
      }
      
      if(czywolne(a[id])){
        p[s[id]] = a[id];
        zajmnij(a[id]);
        if(licza(id+1)){
          return 1;
        }
        p[s[id]] = -1;
        zajmnij(a[id]);
      }
      if(czywolne(b[id])){
        p[s[id]] = b[id];
        zajmnij(b[id]);
        return liczb(id+1);
      }
    }
    return 0;
  }
  void run(){
    cin >> k;
    p.resize(k,-1);
    uz = (1 << k) - 1;
    cin >> s >> a >> b;
    xx(s);xx(a);xx(b);
    n = SZ(s);
    if(liczoba(0)){
      cout << "YES\n";
      string res;
      int j = 0;
      R(i,k){
        if(p[i] != -1){
          res += p[i] + 'a';
          debug(i,p[i]);
        }else{
          while(czywolne(j) == 0) j++;
          res += j + 'a';
          j++;
        }
      }
      cout << res << "\n";
#ifdef LOCAL
      for(char& el:s){
        el = res[el] -'a';
      }
      assert(a <= s && s <= b);
      sort(ALL(res));
      R(i,k){
        assert(res[i] == i + 'a');
      }
#endif
    }else{
      cout << "NO\n";
    }
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int t;
  cin >> t;
  while(t--){
    Sol sol;
    sol.run();
  }
}