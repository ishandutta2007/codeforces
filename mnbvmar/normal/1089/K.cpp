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

struct Node {
  LL node_sum;
  LL max_suf;
  
  Node Merge(const Node &other) const {
    return Node{node_sum + other.node_sum,
      max(other.max_suf, max_suf + other.node_sum)};
  }
};

constexpr int Base = 1 << 20;

Node tree[Base * 2];

void AddVal(int v, int x) {
  v += Base;
  tree[v].node_sum += x;
  tree[v].max_suf = max<LL>(0, tree[v].node_sum);
  v /= 2;
  
  while (v) {
    tree[v] = tree[v * 2].Merge(tree[v * 2 + 1]);
    v /= 2;
  }
}

LL GetMaxSuf(int L, int R) {
  L += Base;
  R += Base;
  if (L == R)
    return tree[R].max_suf;
  Node ans_l = tree[L], ans_r = tree[R];
  
  while (L / 2 != R / 2) {
    if (L % 2 == 0) { ans_l = ans_l.Merge(tree[L + 1]); }
    if (R % 2 == 1) { ans_r = tree[R - 1].Merge(ans_r); }
    L /= 2; R /= 2;
  }
  
  return ans_l.Merge(ans_r).max_suf;
}

const int MaxQ = 3e5 + 100;

int add_time[MaxQ];
int add_size[MaxQ];
int increase[Base];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  for (int i = Base; i < Base * 2; ++i)
    tree[i].node_sum = -1;
  for (int i = Base - 1; i > 0; --i)
    tree[i].node_sum = tree[i * 2].node_sum + tree[i * 2 + 1].node_sum;
  
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; ++i) {
    char type;
    cin >> type;
    
    if (type == '?') {
      int tm;
      cin >> tm;
      LL suf = GetMaxSuf(0, tm - 1);
      suf += increase[tm];
      cout << suf << "\n";
    } else if (type == '+') {
      cin >> add_time[i] >> add_size[i];
      increase[add_time[i]] += add_size[i];
      AddVal(add_time[i], add_size[i]);
    } else {
      int qid;
      cin >> qid;
      --qid;
      increase[add_time[qid]] -= add_size[qid];
      AddVal(add_time[qid], -add_size[qid]);
    }
  }
}