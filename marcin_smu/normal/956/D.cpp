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

template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
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

const int MAX = 1e5 + 100;
int dp[MAX];
int sum(int x){
  x++;
  int res = 0;
  for(;x;x -= x & -x)
    res+=dp[x];
  return res;
}
void add(int x){
  x++;
  for(;x < MAX;x += x&-x){
    dp[x]++;
  }
}

void odw(vector<int>& x){
  vector<int> pom(SZ(x));
  R(i,SZ(x)){
    pom[x[i]] = i;
  }
  swap(pom,x);
}

int n,w;
vector<int> p1,p2,inv;
int x[MAX],v[MAX];

bool cmp2(int a,int b);
bool cmp1(int a,int b){
  if(a == b)return 0;
  int zn = ((v[a] + w) < 0) ^ (v[b] + w < 0);
  int aa = x[a] * (v[b] + w);
  int bb = x[b] * (v[a] + w);
  if(aa == bb){
    return !cmp2(a,b);
  }else{
    return (aa < bb) ^ zn;
  }
}
bool cmp2(int a,int b){
  if(a == b)return 0;
  int zn = ((v[a] - w) < 0) ^ (v[b] - w < 0);
  int aa = x[a] * (v[b] - w);
  int bb = x[b] * (v[a] - w);
  if(aa == bb){
    return !cmp1(a,b);
  }else{
    return (aa < bb) ^ zn;
  }
}
bool cmp0(int a,int b){
  int zn = (v[a] < 0) ^ (v[b] < 0);
  int aa = x[a] * (v[b]);
  int bb = x[b] * (v[a]);
  if(aa == bb){
    return 0;
  }else{
    return (aa < bb) ^ zn;
  }
} 

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> w;
  R(i,n){
    cin >> x[i] >> v[i];
    p1.PB(i);
    p2.PB(i);
  }
  if(w == 0){
    sort(ALL(p1),cmp0);
    int res = 0;
    int ak = 0;
    R(i,n){
      if(i && x[p1[i]] * v[p1[i-1]] == x[p1[i-1]] * v[p1[i]]){
        ak++;
      }else
        ak = 0;
      res += ak;
    }
    cout << res << "\n";
    return 0;
  }
  sort(ALL(p1),cmp1);
  sort(ALL(p2),cmp2);
  debug(p1,p2);
  odw(p1);
  odw(p2);
  inv.resize(n);
  R(i,n){
    inv[p1[i]] = p2[i];
  }
  int res = 0;
  debug(inv);
  reverse(ALL(inv));
  R(i,n){
    res += sum(inv[i]);
    add(inv[i]);
  }
  cout << res << "\n";
}