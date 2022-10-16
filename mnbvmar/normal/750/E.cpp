#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
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


struct Node {
  int minRemove[5][5];

  Node() {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        minRemove[i][j] = 1e9;
      }
    }
  }

  void print() {
#ifdef LOCAL
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (minRemove[i][j] > 1e8) { cerr << "X "; } else { cerr << minRemove[i][j] << " "; }
      }
      cerr << "\n";
    }
    cerr << "\n";
#endif
  }
};


Node mergeNodes(const Node &lhs, const Node &rhs) {
  Node result;
  for (int i = 0; i < 5; i++) {
    for (int j = i; j < 5; j++) {
      for (int k = j; k < 5; k++) {
        mini(result.minRemove[i][k], lhs.minRemove[i][j] + rhs.minRemove[j][k]);
      }
    }
  }

  return result;
}

const int Base = (1 << 18),
          Size = 2 * Base;

Node tree[Size];

int N, Q;
string data;


Node getIntv(int L, int R) {
  L += Base; R += Base;
  if (L == R) { return tree[L]; }

  Node lres = tree[L], rres = tree[R];
  while (L / 2 != R / 2) {
    if (L % 2 == 0) { lres = mergeNodes(lres, tree[L + 1]); }
    if (R % 2 == 1) { rres = mergeNodes(tree[R - 1], rres); }
    L /= 2; R /= 2;
  }
  return mergeNodes(lres, rres);
}



int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(12);
  cerr << fixed << setprecision(6);
  
  cin >> N >> Q >> data;

  Node id;
  for (int i = 0; i < 5; i++) { id.minRemove[i][i] = 0; }

  for (int i = 0; i < N; i++) {
    Node &cur = tree[Base + i + 1];
    cur = id;

    string s = "2017";
    for (int j = 0; j < 4; j++) {
      if (data[i] == s[j]) {
        cur.minRemove[j][j] = 1;
        cur.minRemove[j][j + 1] = 0;
      }
    }

    if (data[i] == '6') {
      cur.minRemove[3][3] = cur.minRemove[4][4] = 1;
    }

    debug(i);
    cur.print();
  }

  for (int i = Base - 1; i > 0; i--) {
    tree[i] = mergeNodes(tree[2 * i], tree[2 * i + 1]);
  }

  for (int i = 0; i < Q; i++) {
    int L, R;
    cin >> L >> R;
    auto mat = getIntv(L, R);
    debug(i);
    mat.print();
    int res = mat.minRemove[0][4];

    if (res > 1e8) {
      cout << "-1\n";
    } else {
      cout << res << "\n";
    }
  }
}