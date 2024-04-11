#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define LL long long
// #define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define RE(i,n) FOR(i,1,n)
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

template<class C> void mini(C&a4, C b4){a4=min(a4,b4);}
template<class C> void maxi(C&a4, C b4){a4=max(a4,b4);}

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA...a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1,a...);
}

template<class T> ostream&operator<<(ostream&os, vector<T> V) {
  os<<"[";
  for (auto v : V)os<<v<<",";
  return os << "]";
}
template<class L, class R> ostream&operator<<(ostream&os, pair<L,R> P) {
  return os<<"("<<P.st<<","<<P.nd<<")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int MaxIn = 205;

PII achievable[4][4][MaxIn][MaxIn];

vector<PII> GetSetEnds(int max_val) {
  vector<PII> ends;
  for (int i = 0; i < max_val - 1; ++i) {
    ends.emplace_back(i, max_val);
    ends.emplace_back(max_val, i);
  }
  
  for (int win = max_val + 1; win < MaxIn; ++win) {
    ends.emplace_back(win, win - 2);
    ends.emplace_back(win - 2, win);
  }
  
  return ends;
}

void Preproc() {
  vector<PII> set_ends = GetSetEnds(25);
  vector<PII> last_set_ends = GetSetEnds(15);
  
  achievable[0][0][0][0] = PII{-1, -1};
  
  for (int sa = 0; sa <= 2; ++sa)
    for (int sb = 0; sb <= 2; ++sb) {
      const vector<PII> &ends = sa + sb < 4 ? set_ends : last_set_ends;
      for (int a = 0; a < MaxIn; ++a)
        for (int b = 0; b < MaxIn; ++b) {
          if (achievable[sa][sb][a][b].st + achievable[sa][sb][a][b].nd == 0) { continue; }
          
          for (auto [da, db] : ends) {
            const int na = a + da;
            const int nb = b + db;
            if (na >= MaxIn || nb >= MaxIn) { continue; }
            
            const int next_sa = sa + (da > db);
            const int next_sb = sb + (da < db);
            
            achievable[next_sa][next_sb][na][nb] = {da, db};
          }
        }
    }
}

struct Testcase {
  void Run() {
    int a, b;
    cin >> a >> b;
    
    const vector<PII> good_ends{{3, 0}, {3, 1}, {3, 2}, {2, 3}, {1, 3}, {0, 3}};
    
    for (auto [sa, sb] : good_ends) {
      if (achievable[sa][sb][a][b].st + achievable[sa][sb][a][b].nd == 0) { continue; }
      
      int my_sa = sa;
      int my_sb = sb;
      
      vector<PII> sets;
      
      while (my_sa + my_sb) {
        const auto [da, db] = achievable[my_sa][my_sb][a][b];
        sets.emplace_back(da, db);
        a -= da; b -= db;
        my_sa -= (da > db);
        my_sb -= (da < db);
      }
      
      reverse(ALL(sets));
      
      cout << sa << ":" << sb << "\n";
      for (auto [da, db] : sets)
        cout << da << ":" << db << " ";
      cout << "\n";
      return;
    }
    
    cout << "Impossible\n";
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  
  Preproc();
  
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i)
    Testcase().Run();
}