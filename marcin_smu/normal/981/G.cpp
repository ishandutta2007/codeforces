#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define R(i,n) for(int i = 0; i < (n); i++)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
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

template<class T> ostream &operator<<(ostream& os, set<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}

template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.FI << "," << P.SE << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int MAX = 1<<19;
const int P = 998244353;
void add(int &a,int b){
  a += b;
  if(a >= P)
    a-=P;
}
void mnu(int &a,int b){
  a = a * b % P;
}

struct node{
  int val;
  int add;
  int mn;
}dp[MAX];

void dziel(set<PII> &secik,int x){
  auto xxx = secik.lower_bound({x,-1});
  if(xxx != secik.begin()){
    xxx--;
    PII pom = *xxx;
    if(pom.FI < x && pom.SE > x){
      secik.erase(xxx);
      secik.insert({pom.FI,x});
      secik.insert({x,pom.SE});
    }
  }
  
}
set<PII> secik[MAX];
void touch(int nr,int sze){
  if(dp[nr].mn != 1){
    mnu(dp[nr*2].val, dp[nr].mn);
    mnu(dp[nr*2].add, dp[nr].mn);
    mnu(dp[nr*2].mn, dp[nr].mn);
    mnu(dp[nr*2+1].val, dp[nr].mn);
    mnu(dp[nr*2+1].add, dp[nr].mn);
    mnu(dp[nr*2+1].mn, dp[nr].mn);
    dp[nr].mn = 1;
  }
  if(dp[nr].add != 0){
    add(dp[nr*2].val, dp[nr].add * sze % P);
    add(dp[nr*2].add, dp[nr].add);
    add(dp[nr*2+1].val, dp[nr].add * sze % P);
    add(dp[nr*2+1].add, dp[nr].add);
    dp[nr].add = 0;
  }
}

void update(int nr){
  dp[nr].val = dp[nr*2].val;
  add(dp[nr].val, dp[nr*2+1].val);
}

int nn;
void inc(int l,int r){
  function<void(int,int,int)> rec = [&](int nr,int po,int ko){
    if(l >= ko || po >= r)return;
    if(l <= po && ko <= r){      
      add(dp[nr].val,ko - po);
      add(dp[nr].add,1);
      return;
    }
    touch(nr,(ko-po)/2);
    rec(nr*2,po,(po+ko)/2);
    rec(nr*2+1,(po+ko)/2,ko);
    update(nr);
  };
  rec(1,0,nn);
}

void dwoj(int l,int r){
  function<void(int,int,int)> rec = [&](int nr,int po,int ko){
    if(l >= ko || po >= r)return;
    if(l <= po && ko <= r){      
      add(dp[nr].val, dp[nr].val);
      add(dp[nr].add, dp[nr].add);
      add(dp[nr].mn, dp[nr].mn);
      return;
    }
    touch(nr,(ko-po)/2);
    rec(nr*2,po,(po+ko)/2);
    rec(nr*2+1,(po+ko)/2,ko);
    update(nr);
  };
  rec(1,0,nn);
}
int n,q;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> q;
  nn = 1;while(nn <= n)nn *= 2;
  R(i,nn*2){
    dp[i].mn = 1;
  }
  R(i,q){
    int t,l,r;
    cin >> t >> l >> r;
    l--;
    if(t == 1){
      int x;
      cin >> x;
      dziel(secik[x],l);
      dziel(secik[x],r);
      int sl = l;
      auto xxx = secik[x].lower_bound({l,-1});
      while(xxx != secik[x].end() && xxx->FI < r){
        inc(l,xxx->FI);
        dwoj(xxx->FI,xxx->SE);
        l = xxx->SE;
        secik[x].erase(xxx++);
      }
      inc(l,r);
      secik[x].insert({sl,r});
    }else{
      int res = 0;
      function<void(int,int,int)> sum = [&](int nr,int po,int ko){
        if(l >= ko || po >= r)return;
        if(l <= po && ko <= r){
          add(res, dp[nr].val);
          return;
        }
        touch(nr,(ko-po)/2);
        sum(nr*2,po,(po+ko)/2);
        sum(nr*2+1,(po+ko)/2,ko);
      };
      sum(1,0,nn);
      cout << res << "\n";
    }
  }
}