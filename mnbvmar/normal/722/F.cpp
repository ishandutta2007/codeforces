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

template<class C> void mini(C& _a4, C _b4) { _a4 = min(_a4, _b4); }
template<class C> void maxi(C& _a4, C _b4) { _a4 = max(_a4, _b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr << sdbg << '=' << h << endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(CC) {cerr<<#CC<<"=";for(auto&cc:CC)cerr<<cc<<",";cerr<<endl;}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(CC) {}
#define cerr if(0)cout
#endif

const int MaxN = 1e5 + 5,
          MaxM = 1e5 + 5;

const vector<vector<int>> Primes = {
  {32, 16, 8, 4, 2},
  {27, 9, 3},
  {25, 5},
  {7}, {11}, {13}, {17}, {19}, {23}, {29}, {31}, {37}
};

int N, M;
int seqLen[MaxN];
vector<int> seqFactor[MaxN];
vector<int> seqs[MaxN];
vector<pair<int, int>> occurs[MaxM];

int needRem[50], cntNeedRem[50], prevNeedRem[50];


vector<int> pwrFactor(int num) { //factor into powers
  vector<int> res;
  for (int i = 2; i <= num; i++) {
    if (num % i == 0) {
      int x = 1;
      while (num % i == 0) {
        num /= i; x *= i;
      }
      res.push_back(x);
    }
  }
  return res;
}


void debugTab() {
  for (int i = 1; i <= 8; i++) {
    debug(i, needRem[i], cntNeedRem[i], prevNeedRem[i]);
  }
  cerr << "\n";
}


bool hasIntegrity() {
  debugTab();

  for (auto &P : Primes) {
    int lastval = -1;

    for (int v : P) {
      if (cntNeedRem[v] == 0) { continue; }
      if (lastval != -1) {
        if (lastval % v != needRem[v]) { return false; }
      }
      lastval = needRem[v];
    }
  }
  return true;
}


void delRem(int seqId) {
  for (int v : seqFactor[seqId]) {
    needRem[v] = prevNeedRem[v];
    cntNeedRem[v]--;
  }
}


bool tryAddRem(int seqId, int pos) {
  int sz = SZ(seqFactor[seqId]);
  bool fail = false;

  for (int i = 0; i < sz; i++) {
    int v = seqFactor[seqId][i];
    prevNeedRem[v] = needRem[v];
    needRem[v] = pos % v;
    if (cntNeedRem[v] && prevNeedRem[v] != needRem[v]) { fail = true; }
    cntNeedRem[v]++;
  }

  debug("X", fail);
  fail |= !hasIntegrity();
  debug(fail);

  if (fail) { delRem(seqId); }
  return !fail;
}


int solve(int num, int L, int R) {
  debug(num, L, R);
  debugTab();
  debug("XXXXXXXXXXXXXXXX");
  for (int j = 0; j < 50; j++) {
    needRem[j] = -1;
  }

  int rptr = L, result = 0;
  auto &numOcc = occurs[num];

  for (int lptr = L; lptr < R; lptr++) {
    while (rptr < R) {
      if (!tryAddRem(numOcc[rptr].first, numOcc[rptr].second)) { break; }
      rptr++;
    }

    debug(lptr, rptr);
    assert(lptr < rptr);
    maxi(result, rptr - lptr);
    delRem(numOcc[lptr].first);
  }

  return result;
}


int solve(int num) {

  int lptr = 0, S = (int)occurs[num].size(), result = 0;
  while (lptr < S) {
    int rptr = lptr + 1;
    while (rptr < S && occurs[num][rptr].first == occurs[num][rptr - 1].first + 1) { rptr++; }
    maxi(result, solve(num, lptr, rptr));
    lptr = rptr;
  }

  return result;
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    int v;
    cin >> v;
    seqLen[i] = v;
    seqFactor[i] = pwrFactor(v);

    for (int j = 0; j < v; j++) {
      int w;
      cin >> w;
      seqs[i].push_back(w);
      occurs[w].emplace_back(i, j);
    }
  }

  for (int num = 1; num <= M; num++) {
    cout << solve(num) << "\n";
  }
}