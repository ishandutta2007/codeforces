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

const int MaxN = 1e5 + 5;

bool avail[MaxN];
LL sumElems[MaxN];
int fuParent[MaxN];
LL result[MaxN];

int fuFind(int v) {
  if (fuParent[v] == v) { return v; }
  return fuParent[v] = fuFind(fuParent[v]);
}

void fuUnion(int a, int b) {
  a = fuFind(a); b = fuFind(b);
  if (a != b) {
    fuParent[b] = a;
    sumElems[a] += sumElems[b];
  }
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    int v;
    cin >> v;
    sumElems[i] = v;
  }

  iota(fuParent, fuParent + N + 4, 0);

  vector<int> perm;
  for (int i = 0; i < N; i++) {
    int v; cin >> v; perm.push_back(v);
  }
  reverse(ALL(perm));

  LL res = 0;
  int ptr = SZ(perm);
  for (int v : perm) {
    debug(v, sumElems[v]);
    avail[v] = true;
    if (avail[v - 1]) { fuUnion(v - 1, v); }
    if (avail[v + 1]) { fuUnion(v, v + 1); }
    res = max(res, sumElems[fuFind(v)]);
    result[--ptr] = res;
  }

  for (int i = 1; i <= N; i++) {
    cout << result[i] << "\n";
  }
}