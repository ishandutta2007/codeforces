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
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define VI vector<int>
#define PII pair<int,int>
#define LD long double

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


int N, K;
vector<int> ids;


int ccc= 0;

void init() {
#ifdef LOCAL
  ids.resize(N);
  iota(ALL(ids), 0);
  random_shuffle(ALL(ids));
  ids.resize(K);
  debug(ids);
#endif
}

bool ask(int a, int b) {
#ifdef LOCAL
  int ra = 1e9, rb = 1e9;
  for (int v : ids) {
    mini(ra, abs(a - v));
    mini(rb, abs(b - v));
  }
  ccc++;
  return ra <= rb;
#endif
  cout << "1 " << a + 1 << " " << b + 1 << endl;
  string res;
  cin >> res;
  return res == "TAK";
}

void answer(int a, int b) {
#ifdef LOCAL
  debug(a, b);
  int cnt = 0;
  for (int v : ids) {
    if (a == v || b == v) { cnt++; }
  }
  assert(a != b && cnt == 2);
  assert(ccc < 60);
  debug(ccc);
#endif

  cout << "2 " << a + 1 << " " << b + 1 << endl;
  exit(0);
}


int findAny(int lft, int rgt) {
  while (lft < rgt - 1) {
    int mid = (lft + rgt) / 2;
    bool res = ask(mid, mid - 1);
    if (res) {
      lft = mid;
    } else {
      rgt = mid;
    }
  }

  return lft;
}

void tryRight(int lft, int rgt, int x) {
  int r = -1;

  while (lft < rgt - 1) {
    int mid = (lft + rgt) / 2;
    bool res = ask(mid, mid - 1);
    if (res) {
      r = findAny(mid, rgt);
      break;
    } else {
      rgt = mid;
    }
  }

  if (r != -1) { answer(x, r); }
}

void tryLeft(int lft, int rgt, int x) {
  int r = -1;

  while (lft < rgt - 1) {
    int mid = (lft + rgt) / 2;
    bool res = ask(mid, mid - 1);
    if (res) {
      lft = mid;
    } else {
      r = findAny(lft, mid);
      break;
    }
  }

  if (r != -1) { answer(x, r); }
}

int32_t main() {
  cin >> N >> K;

  init();

  int fst = findAny(0, N);
  debug(fst);
  if (fst && ask(fst - 1, fst)) {
    answer(fst - 1, fst);
  }
  if (fst < N - 1 && ask(fst + 1, fst)) {
    answer(fst, fst + 1);
  }

  debug("start right");
  if (fst != N - 1) tryRight(fst + 1, N, fst);
  debug("start left");
  if (fst) tryLeft(0, fst, fst);
}