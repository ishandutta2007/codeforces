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

#define MAX 1000101
int n,m;
vector<pair<int,int> > d[MAX];
int deg[MAX];
vector<vector<int>> res,t,xn,xm;
vector<int> s1,s2;
int czn[MAX],czm[MAX];
void zm(vector<int>& x){
 // debug("zm");
 // debugv(x);
  if(x.empty()){
    return;
  }
  int co = x.back();
  while(!x.empty()){
    if(x.back() == co){
      deg[co]--;
      x.pop_back();
    }else
      break;
  }
  if(deg[co] == 0){
    s2.PB(co);
  }
}
int f[MAX];
int find(int a){
  return f[a] == a?a:f[a] = find(f[a]);
}
void uni(int a,int b){
  a = find(a);
  b = find(b);
  f[a] = b;
}
void uni2(int a,int b,int c,int d){
  uni(a*m+b,c*m+d);
}
#undef int
int main(){
#define int LL
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  res.resize(n,vector<int>(m));
  t.resize(n,vector<int>(m));
  R(i,n*m){
    f[i] = i;
  }
  set<PII> s;
  map<PII,int> skal;
  R(i,n)R(j,m){
    cin >> t[i][j];
  }
  R(i,n){
    vector<PII> pom;
    R(j,m){
      pom.PB({t[i][j],j});
    }
    sort(ALL(pom));
    R(j,m-1){
      if(pom[j].FI == pom[j+1].FI){
        uni2(i,pom[j].SE,i,pom[j+1].SE);
      }
    }
  }
  R(j,m){
    vector<PII> pom;
    R(i,n){
      pom.PB({t[i][j],i});
    }
    sort(ALL(pom));
    R(i,n-1){
      if(pom[i].FI == pom[i+1].FI){
        uni2(pom[i].SE,j,pom[i+1].SE,j);
      }
    }
  }
  R(i,n)R(j,m){
    s.insert({t[i][j],find(i*m+j)});
  }
  int il = 0;
  for(auto x:s){
    skal[x] = il++;
  }
  R(i,n)R(j,m){
    t[i][j] = skal[{t[i][j],find(i*m+j)}];
    deg[t[i][j]] += 2;
    d[t[i][j]].PB({i,j});
  }
  R(i,n){
    vector<int> pom;
    R(j,m){
      pom.PB(t[i][j]);
    }
    sort(ALL(pom),greater<int>());
    zm(pom);
    xn.PB(pom);
  }
  
  R(j,m){
    vector<int> pom;
    R(i,n){
      pom.PB(t[i][j]);
    }
    sort(ALL(pom),greater<int>());
    zm(pom);
    xm.PB(pom);
  }
  int wyn = 0;
  while(!s2.empty()){
    swap(s1,s2);
    s2.clear();
    wyn ++;
    for(int k:s1){
      for(PII x:d[k]){
        res[x.FI][x.SE] = wyn;
        if(czn[x.FI] != wyn){
          czn[x.FI] = wyn;
          zm(xn[x.FI]);
        }
        if(czm[x.SE] != wyn){
          czm[x.SE] = wyn;
          zm(xm[x.SE]);
        }
      }
    }
  }
  R(i,n){
    R(j,m){
      cout << res[i][j] << " ";
    }
    cout << "\n";
  }
}