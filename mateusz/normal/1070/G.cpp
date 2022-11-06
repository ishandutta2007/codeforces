#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for (int i = (a) ; i<= (b); i++)
#define FORD(i,a,b) for (int i = (a) ; i>= (b); i--)
#define REP(i, n) FOR(i,0,(int)(n) - 1)
#define st first
#define nd second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define VI vector<int>
#define PII pair<int,int>

template<class C> void mini(C& a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C& a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream &os, vector<T> V){
  os<<"[";for(auto vv:V)os<<vv<<",";return os<<"]";
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

int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin>>n>>m;
  vector<PII> heroes(m);
  VI hero(n, -1);
  REP(i, m){
    int s,h;
    cin>>s>>h;
    s--;
    heroes[i] = {s,h};
    hero[s] = i;
  }
  VI pole(n);
  REP(i, n){
    cin>>pole[i];
  }
  VI res;
  REP(i, n){
    for(PII pos: vector<PII>({{i, i + 1}, {i - 1, i}})){
      debug(i);
      VI kolejnosc[2];
      VI idle;
      int idxr = pos.st;
      bool lastOk = hero[i] != -1;
      if(hero[i] != -1){
        idle.PB(hero[i]);
      }
      bool washero = hero[i] != -1;
      FORD(j, i - 1, 0){
        if(hero[j] == -1)
          continue;
        washero = washero || (pos.st == i);
        int hp = heroes[hero[j]].nd;
        bool died = false;
        FOR(k, j + 1, idxr){
          hp += pole[k];
          died = died || hp < 0;
        }
        debug(j, heroes[hero[j]], died);
        if(died){
          lastOk = false;
          idle.PB(hero[j]);
        } else{
          lastOk = true;
          idxr = j - 1;
          kolejnosc[0].PB(hero[j]);
        }
      }
      if(!lastOk){
        continue;
      }
      lastOk = hero[i] != -1;
      int idxl = pos.nd;
      FOR(j, i + 1, n - 1){
        if(hero[j] == -1){
          continue;
        }
        washero = washero || pos.st == i - 1;
        int hp = heroes[hero[j]].nd;
        bool died = false;
        FORD(k, j - 1, idxl){
          hp += pole[k];
          died = died || hp < 0;
        }
        debug(j, heroes[hero[j]], died);
        if(died){
          lastOk = false;
          idle.PB(hero[j]);
        } else{
          lastOk = true;
          idxl = j + 1;
          kolejnosc[1].PB(hero[j]);
        }
      }
      if(!lastOk || !washero)
        continue;
      cout<<i + 1<<endl;
      if(pos.st == i){
        for(int a: kolejnosc[0]){
          cout<<a + 1<<" ";
        }
        for(int a: kolejnosc[1]){
          cout<<a + 1<<" ";
        }
        
      } else{
        for(int a: kolejnosc[1]){
          cout<<a + 1<<" ";
        }
        for(int a: kolejnosc[0]){
          cout<<a + 1<<" ";
        }
      }
      for(int a: idle){
        cout<<a + 1<<" ";
      }
      return 0;
    }
  }
  cout<<-1<<endl;
}