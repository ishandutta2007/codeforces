#include <bits/stdc++.h>

using namespace std;
#define MP make_pair
#define PB push_back
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

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(C) {for(auto&c:C)cerr<<c<<",";cerr<<endl;}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(C) {}
#define cerr if(0) cout
#endif

#define MAX 200010
vector<int> d[MAX];
int n,k;
int v[MAX];
bool wyb[MAX];
int gl;
int ile;
int pod0[MAX];
int dfs0(int nr,int oj){
  pod0[nr] = (wyb[nr] == 0);
  for(int ak:d[nr])
    if(ak != oj)
      pod0[nr] += dfs0(ak,nr);
  return pod0[nr];
}
int podq[MAX];
int dfsq(int nr,int oj){
  podq[nr] = 1;
  for(int ak:d[nr])
    if(ak != oj)
      podq[nr] += dfsq(ak,nr);
  return podq[nr];
}
pair<int,bool> dfs(int nr,int oj){
  if(!wyb[nr]){
    for(int ak:d[nr])
      if(ak != oj)
        dfs(ak,nr);
    return {0,false};
  }
  vector<int> rec;
  int res = 1;
  bool czyc = 1;
  for(int ak:d[nr]){
    if(ak != oj){
      bool czy;
      int war;
      tie(war,czy) = dfs(ak,nr);
      if(czy){
        res += war;
      }else{
        czyc = 0;
        rec.PB(war);
      }
    }
  }
  while(SZ(rec) < 2)rec.PB(0);
  sort(ALL(rec),greater<int>());
  int pomm = res + rec[0] + rec[1]; 
  if(ile == pod0[nr]){
    pomm += n - podq[nr];
    debug(nr,pomm,podq[nr]);
  } 
  if(pomm >= k)
    gl = 1;
  return {res+rec[0],czyc};
}
bool spr(int gr){
  ile = n;
  R(i,n){
    if(wyb[i] = v[i] >= gr){
      ile--;
    }
  }
  gl = 0;
  dfs0(0,-1);
  dfsq(0,-1);
  dfs(0,-1);
  return gl;
}

#undef int
int main(){
#define int LL
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout<<fixed<<setprecision(11);
  cin >> n >> k;
  R(i,n)cin >> v[i];
  R(i,n-1){
    int a,b;
    cin >> a >> b;
    a--; b--;
    d[a].PB(b);
    d[b].PB(a);
  }
  int po = 1,ko = 1e6+1;
  while(po+1!=ko){
    int m = (po+ko)/2;
    if(spr(m))
      po = m;
    else
      ko = m;
  }
  cout << po << endl;
}