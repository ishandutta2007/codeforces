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

template<class C> void mini(C&a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C&a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<endl;}
template<class TH, class...TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<",";_dbg(sdbg+1, a...);
}

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
  os<<"[";for(auto vv:V)os<<vv<<","; os<<"]";
  return os;
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) {
  os<<"("<<P.first<<","<<P.second<<")";
  return os;
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif



struct Test {
  int height;
  int N;
  vector<vector<int>> adj;
  vector<bool> isAsked;
  int start;

  vector<int> ask(int v) {
    debug("ask", v);
    isAsked[v] = true;
#ifdef LOCAL
    debug(adj[v]);
    return adj[v];
#else
    if (SZ(adj[v])) { return adj[v]; }
    cout << "? " << v << endl;

    int amount;
    cin >> amount;
    for (int i = 0; i < amount; i++) {
      int w;
      cin >> w;
      adj[v].push_back(w);
    }
    return adj[v];
#endif
  }

  bool known(int v) {
    return isAsked[v];
  }

  void answer(int v) {
    cout << "! " << v << endl;
#ifdef LOCAL
    assert(v == start);
#endif
  }


  bool toLeaf(int vert, int parent, int dist) {
    if (SZ(ask(vert)) == 1) { return true; }
    if (dist == 0) { return false; }

    vector<int> rem;
    for (int s : ask(vert)) {
      if (s != parent && known(s)) { return toLeaf(s, vert, dist - 1); }
    }
    for (int s : ask(vert)) {
      if (s != parent) { return toLeaf(s, vert, dist - 1); }
    }
    return false;
  }

  int discard = -1;


  int traverse(int vert, int depth, int from, int fromLeaf) {
    debug("traverse", vert, depth, fromLeaf);
    if (depth <= 2) { discard = from; return vert; }

    vector<int> X;
    for (int s : ask(vert)) {
      if (s != from) { X.PB(s); }
    }

    assert(SZ(X));
    for (int i = 0; i < SZ(X) - 1; i++) {
      int s = X[i];
      debug(s);
      if (!toLeaf(s, vert, fromLeaf)) {
        return traverse(s, depth - 1, vert, fromLeaf + 1);
      }
    }

    return traverse(X.back(), depth - 1, vert, fromLeaf + 1);
  }




  int checkAll(int vert, int dist) {
    debug("checkAll", vert, dist);
    vector<int> checked{vert};
    for (int i = 0; i < dist; i++) {
      VI nchecked;
      for (int v : checked) {
        for (int s : ask(v)) { if (s != vert && s != discard) nchecked.push_back(s); }
      }
      checked = nchecked;
    }

    sort(ALL(checked));
    checked.resize(unique(ALL(checked)) - checked.begin());
    debug(checked);

    for (int i = 0; i < SZ(checked) - 1; i++) {
      if (SZ(ask(checked[i])) == 2) { return checked[i]; }
    }
    return checked.back();
  }


  vector<bool> taken;
  void create(int height, int parent = -1) {
    vector<int> avail;
    for (int i = 1; i <= N; i++) {
      if (!taken[i]) { avail.PB(i); }
    }
    int x = avail[rand() % SZ(avail)];
    if (parent > 0) {
      adj[parent].PB(x);
      adj[x].PB(parent);
    }

    if (start == -1) { start = x; }
    taken[x] = true;
    if (height == 1) {
      return;
    }
    create(height - 1, x);
    create(height - 1, x);
  }


  void run() {
    cin >> height;
    N = (1 << height) - 1;
    adj.resize(N + 1);
    isAsked.resize(N + 1);
#ifdef LOCAL
    taken.resize(N+1, false);
    start = -1;
    create(height);
    debug(adj);
    for (int i = 0; i <= N; i++) { sort(ALL(adj[i])); }
#endif

    debug(height);

    if (SZ(ask(1)) == 2) {
      answer(1); return;
    }

    int depth1 = height - 1;

    if (SZ(adj[1]) == 3) {
      queue<PII> Q;
      Q.push(MP(1, 0));
      
      while (true) {
        int vert, dist;
        tie(vert, dist) = Q.front();
        debug(vert, dist);
        Q.pop();
        auto neighbors = ask(vert);
        debug(neighbors, SZ(neighbors));
        if (SZ(neighbors) == 2) { answer(vert); return; }
        if (SZ(neighbors) == 1) { depth1 -= dist; break; }
        for (int other : neighbors) {
          if (known(other)) { continue; }
          Q.push(make_pair(other, dist + 1));
          if (vert != 1) break;
        }
      }
    }

    if (depth1 <= 2) {
      answer(checkAll(1, depth1));
    } else {
      answer(checkAll(traverse(1, depth1, -1, height - 1 - depth1), 2));
    }
  }

  void check() {
    debug(count(ALL(isAsked), true));
    assert(count(ALL(isAsked), true) <= 16);
  }
};



int32_t main() {
  int T;
  cin >> T;

  for (int i = 1; i <= T; i++) {
    debug("test", i);
    Test test;
    test.run();
#ifdef LOCAL
    test.check();
#endif
  }

}