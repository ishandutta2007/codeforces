#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
typedef double D;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define R(I,N) for(int I=0;I<N;I++)
#define F(I,A,B) for(int I=A;I<B;I++)
#define FD(I,N) for(int I=N-1;I>=0;I--)
#define make(A) scanf("%d",&A)
#define make2(A,B) scanf("%d%d",&A,&B)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
template<typename C> void maxi(C& a,C b){if(a<b)a=b;}
template<typename C> void mini(C& a,C b){if(a>b)a=b;}

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a){
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(C) {for(auto&c:C)cerr<<c<<",";cerr<<endl;}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(C) {}
#define cerr if(0)cout
#endif

#define MAX 300100
int n,c[MAX],f[MAX],odj[MAX];
vector<int> d[MAX][30],d0[MAX];
char z[MAX];
vector<int> zap[MAX];
int find(int a){
  return f[a] == a?a:f[a] = find(f[a]);
}
void uni(int a,int b){
  a = find(a);
  b = find(b);
  f[b] = a;
}
bool cz[MAX];
int dfsTar(int a,int oj){
  int roz = 1;
  for(int ak : d0[a]){
    if(ak != oj){
      roz += dfsTar(ak,a);
      uni(a,ak);
    }
  }
  for(int ak:zap[a]){
    if(cz[ak]){
      odj[find(ak)]++;
    }
  }
  cz[a] = 1;
  c[a] += roz;
  return roz;
}
const int ALFA = 'z' - 'a' + 1;
void dfs(vector<int> x){
  if(SZ(x) == 0)return;
  debugv(x);
  R(i,SZ(x)-1){
    debug("lacze",x[i],x[i+1]);
    zap[x[i]].PB(x[i+1]);
    zap[x[i+1]].PB(x[i]);
  }
  R(i,ALFA){
    vector<int> v;
    for(int ak:x)for(int ak2:d[ak][i]){
      v.PB(ak2);
    }
    dfs(v);
  }
}
void dfs0(int a,int oj){
  for(int ak:d0[a]){
    if(ak != oj){
      d[a][z[ak]-'a'].PB(ak);
      dfs0(ak,a);
    }
  }
}
int dfs_odj(int a,int oj){
  int war = odj[a];
  for(int ak:d0[a]){
    if(ak != oj){
      war += dfs_odj(ak,a);
    }
  }
  c[a] -= war;
  return war;
}
main(){
  make(n);
  R(i,n)make(c[i]);
  scanf(" %s",z);
  R(i,n-1){
    int a,b;
    make2(a,b);
    a--;b--;
    d0[a].PB(b);
    d0[b].PB(a);
  }
  dfs0(0,-1);
  dfs({0});
  debug("po dfs");
  R(i,n)f[i] = i;
  dfsTar(0,-1);
  dfs_odj(0,-1);
  int max = -1;
  int il = 0;
  R(i,n){
    debug(c[i]);
    if(c[i] > max){
      il = 0;
      max = c[i];
    }
    if(c[i] == max)
      il++;
  }
  printf("%d %d\n",max,il);
}