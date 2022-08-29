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
#define MAX 501
int n,m;
int t[MAX][MAX],t2[MAX][MAX];
const int inf = 1e9;
main(){
  make2(n,m);
  R(i,n)R(j,n){
    t[i][j] = t2[i][j] = inf;
  }
  R(i,m){
    int a,b;
    make2(a,b);
    a--;b--;
    t[a][b] = 1;
    t[b][a] = 1;
  }
  R(i,n)R(j,n){
    if(t[i][j] == inf)
      t2[i][j] = 1;
  }
  R(i,n)R(j,n)R(k,n)mini(t[j][k],t[j][i] + t[i][k]);
  R(i,n)R(j,n)R(k,n)mini(t2[j][k],t2[j][i] + t2[i][k]);
  if(t[0][n-1] == inf || t2[0][n-1] == inf){
    puts("-1");
  }else{
    printf("%d\n",max(t[0][n-1],t2[0][n-1]));
  }
}