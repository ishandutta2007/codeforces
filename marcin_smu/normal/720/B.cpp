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

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream& operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto& vv : V) os << vv << ","; os << "]";
  return os;
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int MAX = 30000;
int a[MAX],b[MAX],c[MAX],f[MAX];
set<int> inc[MAX];
vector<int> d[MAX];
int deg[MAX];
int n,m;
int find(int a){
  return f[a] == a ? a : f[a] = find(f[a]);
}
vector<int> todo;
void wrzuc(set<int>& a,set<int>& b){
  for(int el:b){
    if(!a.insert(el).SE){
      deg[c[el]]--;
      if(deg[c[el]] == 1)
        todo.PB(c[el]);
      a.erase(el);
    }
  }
  set<int> pom;
  swap(pom,b);
}

bool uni(int i){
  int a = find(::a[i]);
  int b = find(::b[i]);
  if(a == b)return 0;
  if(SZ(inc[a]) < SZ(inc[b])){
    wrzuc(inc[b],inc[a]);
    f[a] = b;
  }else{
    wrzuc(inc[a],inc[b]);
    f[b] = a;
  }
  return 1;
}
int res = 0;
void rob(int k){
  for(int i:d[k]){
    if(uni(i)){
      res++;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  R(i,n)f[i] = i;
  R(i,m){
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;b[i]--;c[i]--;
    inc[a[i]].insert(i);
    inc[b[i]].insert(i);
    d[c[i]].PB(i);
    deg[c[i]]++;
  }
  R(i,m){
    if(deg[i] == 1)
      todo.PB(i);
  }
  R(i,SZ(todo)){
    rob(todo[i]);
  }
  R(i,m){
    if(deg[i] > 1)res++;
  }
  cout << res << endl;
  
}