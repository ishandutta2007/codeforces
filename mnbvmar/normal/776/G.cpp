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


const vector<string> wbit = {
  "13579bdf",
  "2367abef",
  "4567cdef",
  "89abcdef"
};
const string S = "0123456789abcdef";


vector<LL> getCountInner(int maxLen, char maxCh, int specHex, string hexOpts) {
  vector<LL> result{1};

  for (int i = 0; i < maxLen; i++) {
    const string &chs = (i == specHex ? hexOpts : S);
    int cnt = 0;
    for (char ch : chs) {
      if (ch > maxCh) { break; }
      cnt++;
    }
    result.push_back(result.back() * cnt);
  }
  return result;
}


LL getCountMain(const string &x, char maxCh, int specHex, string hexOpts) {
  if (specHex >= SZ(x)) { return 0; }
  LL res = 0;
  vector<LL> inners = getCountInner(SZ(x), maxCh, specHex, hexOpts);

  for (int i = 0; i < SZ(x); i++) {
    int bit = SZ(x) - i - 1;
    const string &chs = (bit == specHex ? hexOpts : S);

    bool same = false;

    for (char ch : chs) {
      if (ch > maxCh) { break; }
      if (ch > x[i]) { break; }
      if (ch < x[i]) { res += inners[bit]; continue; }
      if (ch == x[i]) {
        same = true;
      }
    }

    if (same && !bit) {
      res++;
    }
    if (!same) { break; }
  }

  return res;
}



LL getCount(string x) {
  LL result = 0;

  for (int i = 0; i < 16; i++) {
    result += getCountMain(x, S[i], i / 4, wbit[i % 4]);

    if (i) {
      result -= getCountMain(x, S[i - 1], i / 4, wbit[i % 4]);
    }
    debug(i, result);
  }

  return result;
}



string sub1(string x) {
  if (x == "0") { return x; }
  stringstream ss;
  ss << std::hex << stoll(x, 0, 16) - 1;
  return ss.str();
}

void process() {
  string l, r;
  cin >> l >> r;

  l = sub1(l);
  debug(l, r);
  cout << getCount(r) - getCount(l) << "\n";
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int Q;
  cin >> Q;
  while (Q--) {
    process();
  }
}