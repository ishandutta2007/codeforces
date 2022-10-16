#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
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

const int N = 2e5 + 5;
set<int> slo[N];
int wei[N];
int n, m;
int alive[N];
int res = 0;
void Check(int v) {
  if (!alive[v]) { return; }
  if (SZ(slo[v]) == 1) {
    int nei = *(slo[v].begin());
    assert(alive[nei]);
    alive[v] = 0;
    res += wei[v] * (n - wei[v]);
    wei[nei] += wei[v];
    slo[v].clear();
    slo[nei].erase(v);
    Check(nei);
  }
}
struct Edge {
  int a, b;
  vector<int> weis, pref, suf;
  vector<int> sp, ss;
  friend ostream& operator<<(ostream& out, Edge& e) {
    return out<<"("<<e.a<<", "<<e.b<<", "<<e.weis<<")";
  }
  
};
int is_imp[N];
int idx[N];
int vis[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  
  cin>>n>>m;
  RE (i, m) {
    int a, b;
    cin>>a>>b;
    slo[a].insert(b);
    slo[b].insert(a);
  }
  RE (i, n) {
    wei[i] = 1;
    alive[i] = 1;
  }
  RE (i, n) {
    Check(i);
  }
  vector<int> all_alive;
  vector<int> imps;
  RE (i, n) {
    if (!alive[i]) { continue; }
    all_alive.PB(i);
    if (SZ(slo[i]) > 2) {
      imps.PB(i);
    }
  }
  if (all_alive.empty()) {
    cout<<res<<endl;
    return 0;
  }
  if (imps.empty()) {
    imps.PB(all_alive[0]);
    //imps.PB(all_alive[1]);
  }
  int cnt = 0;
  for (auto v : imps) {
    idx[v] = cnt++;
    is_imp[v] = 1;
  }
  debug(res, imps);
  int compr = SZ(imps);
  const int kInf = 1e9;
  vector<VI> dis(compr, VI(compr, kInf));
  vector<Edge> edges;
  REP (i, compr) {
    dis[i][i] = 0;
    int v = imps[i];
    for (auto nei : slo[v]) {
      if (is_imp[nei]) { mini(dis[idx[v]][idx[nei]], 1ll); mini(dis[idx[nei]][idx[v]], 1ll); continue; }
      if (is_imp[nei] || vis[nei]) { continue; }
      vector<int> weis{0};
      int prv = v;
      while (1) {
        vis[nei] = 1;
        weis.PB(wei[nei]);
        if (is_imp[nei]) { break; }
        assert(SZ(slo[nei]) == 2);
        int nxt = *(slo[nei].begin()) + *(next(slo[nei].begin()));
        nxt -= prv;
        prv = nei;
        nei = nxt;
      }
      weis.back() = 0;
      //if (v < nei) {
        edges.PB({idx[v], idx[nei], weis, {}, {}, {}, {}});
      //}
      mini(dis[idx[v]][idx[nei]], SZ(weis) - 1);
      mini(dis[idx[nei]][idx[v]], SZ(weis) - 1);
    }
  }
  REP (k, compr) {
    REP (i, compr) {
      REP (j, compr) {
        mini(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  debug(edges);
  debug(dis);
  
  REP (i, compr) {
    REP (j, i) {
      res += wei[imps[i]] * wei[imps[j]] * dis[i][j];
    }
  }
  debug(res);
  REP (i, compr) {
    for (auto e : edges) {
      int dL = dis[i][e.a], dR = dis[i][e.b];
      RE (j, SZ(e.weis) - 2) {
        int d = min(dL + j, dR + SZ(e.weis) - 1 - j);
        res += d * wei[imps[i]] * e.weis[j];
      }
    }
  }
  debug(res);
  for (auto& e : edges) {
    e.pref.PB(0);
    e.sp.PB(0);
    RE (j, SZ(e.weis) - 1) {
      e.pref.PB(e.pref.back() + j * e.weis[j]);
      e.sp.PB(e.sp.back() + e.weis[j]);
    }
    e.suf.PB(0);
    e.ss.PB(0);
    for (int j = SZ(e.weis) - 2; j >= 0; j--) {
      e.suf.PB(e.suf.back() + e.weis[j] * (SZ(e.weis) - 1 - j));
      e.ss.PB(e.ss.back() + e.weis[j]);
    }
  }
  for (int ei = 0; ei < SZ(edges); ei++) {
    for (int ej = 0; ej < ei; ej++) {
      auto& e1 = edges[ei];
      auto& e2 = edges[ej];
      debug(e1.weis, e2.weis);
      int L1 = SZ(e1.weis) - 1, L2 = SZ(e2.weis) - 1;
      RE (i, SZ(e1.weis) - 2) {
        int dL = min(i + dis[e1.a][e2.a], L1 - i + dis[e1.b][e2.a]);
        int dR = min(i + dis[e1.a][e2.b], L1 - i + dis[e1.b][e2.b]);
        assert(abs(dL - dR) <= L2);
        int x = (dR + L2 - dL /*+ 1*/) / 2;
        debug(dL, dR, L2, x, L2 - x - 1);
        res += e1.weis[i] * e2.pref[x];
        assert(x <= L2);
        if (x <= L2 - 1) {
          res += e1.weis[i] * e2.suf[L2 - x - 1];
        }
        res += e1.weis[i] * dL * e2.sp[x];
        if (x <= L2 - 1) {
          res += e1.weis[i] * dR * e2.ss[L2 - x - 1];
        }
      }
    }
  }
  debug(res);
  int pom = 0;
  for (auto e : edges) {
    int d = dis[e.a][e.b];
    int L = d + SZ(e.weis) - 1;
    REP (tr, 2) {
      vector<int> cyc_weis = e.weis;
      cyc_weis.insert(cyc_weis.end(), ALL(e.weis));
      vector<int> lens;
      REP (i, SZ(e.weis) - 1) {
        lens.PB(1);
      }
      lens.PB(d);
      REP (i, SZ(e.weis) - 1) {
        lens.PB(1);
      }
      int sum_dises = 0, sum_guys = 0;
      int fur = 1, curL = 0;
      RE (i, SZ(e.weis) - 2) {
        while (1) {
          int nfurL = curL + lens[fur];
          int nfurR = L - nfurL;
          if (nfurL < nfurR || (nfurL == nfurR && tr)) {
            fur++;
            sum_dises += nfurL * cyc_weis[fur];
            sum_guys += cyc_weis[fur];
            curL = nfurL;
          } else {
            break;
          }
        }
        pom += e.weis[i] * sum_dises;
        sum_dises -= lens[i] * sum_guys;
        sum_guys -= cyc_weis[i + 1];
        curL -= lens[i];
      }
      //debug(res);
      reverse(ALL(e.weis));
    }
  }
  assert(pom % 2 == 0);
  res += pom / 2;
  cout<<res<<endl;
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
}