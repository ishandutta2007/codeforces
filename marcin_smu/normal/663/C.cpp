#include <bits/stdc++.h>

using namespace std;
#define MP make_pair
#define PB push_back
#define LD long double
#define LL long long
#define int LL
#define FI first
#define SE second
#define R(i,n) for(int i=0;i<n;i++)
#define F(i,a,b) for(int i=a;i<b;i++)
#define FD(i,n) for(int i=n-1;i>=0;i--)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PII pair<int,int>
#define VI vector<int>

template<class C> void mini(C&a4, C b4){a4=min(a4,b4);}
template<class C> void maxi(C&a4, C b4){a4=max(a4,b4);}

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a){
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1,a...);
}

template<class T> ostream& operator<<(ostream& os, vector<T> V) {
  os << "[";
  for (auto& tt : V) { os << tt << ","; }
  os << "]";
  return os;
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0) cout
#endif

#define MAX 100001

int n,m;
vector<PII> d[MAX];
vector<int> k[2][MAX];
void add(int a,int b,int w){
  d[a].PB({b,w});
  d[b].PB({a,w});
}
void nie(){
  cout << "-1\n";
  exit(0);
}

vector<int> x[2];
bool cz[MAX];
int kol[MAX];
bool dfs(int i){
  cz[i] = 1;
  x[kol[i]].PB(i);
  for(PII el:d[i]){
    if(!cz[el.FI]){
      kol[el.FI] = kol[i] ^ el.SE;
      if(dfs(el.FI))return 1;
    }
    if(kol[el.FI] != (kol[i] ^ el.SE))
      return 1;
  }
  return 0;
}

vector<int> licz(int jak){
  R(i,n){
    d[i].clear();
    cz[i] = 0;
    kol[i] = 0;
  }
  R(i,n){
    R(z,2){
      R(j,SZ(k[z][i]))
        add(i,k[z][i][j],z ^ jak);
    }
  }
  vector<int> res;
  R(i,n){
    if(cz[i] == 0){
      x[0].clear();
      x[1].clear();
      if(dfs(i)) return {-1ll};
      if(SZ(x[1]) < SZ(x[0]))
        swap(x[0],x[1]);
      for(int el:x[0])
        res.PB(el);
    }
  }
  return res;
}

bool zle(vector<int> &a){
  return (SZ(a) && a[0] == -1);
}
#undef int
int main(){
#define int LL
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(11);
  cin >> n >> m;
  R(i,m){
    int a,b;char c;
    cin >> a >> b >> c;
    a--;b--;
    k[c == 'B'][a].PB(b);
    k[c == 'B'][b].PB(a);
  }
  vector<int> res;
  res.PB(-1);
  R(i,2){
    vector<int> res1 = licz(i);
    if(zle(res) || (!zle(res1) && SZ(res1) < SZ(res)))
      res = res1;
  }
  if(zle(res)){
    nie();
  } 
  cout << SZ(res) << "\n";
  for(int el:res)
    cout << el + 1 << " ";
  cout << "\n";
  
}