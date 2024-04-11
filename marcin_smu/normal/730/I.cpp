#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
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

template<class C> void mini(C& a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C& a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h) {cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
  os << "["; for (auto v : V) os << v << ","; os << ']'; return os;
}

template<class L, class R> ostream &operator<<(ostream &os, pair<L, R> P ){
  return os << "(" << P.st << ", " << P.nd << ")";
}


#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif
const int N = 3e3 + 5;

struct Guy {
  int st, nd, ind;
};

Guy g[N];

bool CmpMax(Guy a, Guy b) {
  return max(a.st, a.nd) > max(b.st, b.nd);
}

bool CmpP(Guy a, Guy b) {
  return a.st > b.st;
}
int a[N], b[N];

int n, p, s;
bool calc(int aktc){
  debug(aktc);
  RE (i, n) {
    g[i] = {a[i], b[i] + aktc, i};
  }
  sort(g + 1, g + 1 + n, CmpMax);
  int cand = 0;
  int eq = 0, count_p = 0, count_s = 0, eq2 = 0;
  int i = 1;
  auto val = [&](int i){
    return max(g[i].FI, g[i].SE);
  };
  vector<Guy> cand_p, cand_s;
  for(;val(i) > val(p+s); i++){
    if (g[i].FI > g[i].SE) {
      cand_p.PB(g[i]);
    } else if(g[i].FI < g[i].SE){
      cand_s.PB(g[i]);
    } else {
      eq++;
    }
  }
  int left = p + s - i + 1;
  debug(left);
  if(SZ(cand_p) > p)return 1;
  if(SZ(cand_s) > s)return 0;
  for(;i <= n && val(i) == val(p+s); i++){
    if (g[i].st > g[i].nd) {
      count_p ++;
    } else if (g[i].st < g[i].nd) {
      count_s ++;
    } else 
      eq2 ++;
  }
  debug(aktc, SZ(cand_p), count_p, eq, eq2, p, SZ(cand_s), count_s, eq, eq2, s);
  if(SZ(cand_p) + count_p + eq + eq2 < p)return 0;
  if(SZ(cand_s) + count_s + eq + eq2 < s)return 1;
  debug("??");
  
  i = 1;
  for(;val(i) > val(p+s);i++){
    if (g[i].FI == g[i].SE){
      if(SZ(cand_s) == s || SZ(cand_p) + min(left, count_p + eq2) + eq == p){
        cand_p.PB(g[i]);
      } else {
        cand_s.PB(g[i]);
      }
      eq--;
    }
  }
  debug(SZ(cand_p), SZ(cand_s), s);
  int ii = i;
  for(;i <= n && val(i) == val(p+s); i++){
    if (SZ(cand_p) != p && g[i].st > g[i].nd) {
      cand_p.PB(g[i]);
    } else if (SZ(cand_s) != s && g[i].st < g[i].nd) {
      cand_s.PB(g[i]);
    }
  }
  i = ii;
  for(;i <= n && val(i) == val(p+s); i++){
    if (SZ(cand_p) != p && g[i].st == g[i].nd) {
      cand_p.PB(g[i]);
    } else if (SZ(cand_s) != s && g[i].st == g[i].nd) {
      cand_s.PB(g[i]);
    }
  }
  
  int res = 0;
  R(i,p){
    res += cand_p[i].st;
  }
  R(i,s){
    res += cand_s[i].nd - aktc;
  }
  debug(SZ(cand_p), SZ(cand_s));
  cout << res << endl;
  R(i,p){
    cout << cand_p[i].ind << " ";
  }
  cout << "\n";
  R(i,s){
    cout << cand_s[i].ind << " ";
  }
  cout << "\n";
  exit(0);
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  
  cin>>n>>p>>s;
  RE (i, n) {
    cin>>a[i];
  }
  RE (i, n) {
    cin>>b[i];
  }
  
  int kl = -N, kp = N, best = 0;
  VI ps, ss;
  while (kl <= kp) {
    int aktc = (kl + kp) / 2;
    if (calc(aktc)) {
      kl = aktc + 1;
    } else {
      kp = aktc - 1;
    }
  }
  assert(0);

}