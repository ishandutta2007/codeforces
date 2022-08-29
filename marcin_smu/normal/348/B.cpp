#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PI;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef double D;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define R(I,N) for(int I=0;I<N;I++)
#define F(I,A,B) for(int I=A;I<B;I++)
#define FD(I,N) for(int I=N-1;I>=0;I--)
#define make(A) scanf("%d",&A)
#ifdef LOCAL
#define makel(A) scanf("%lld",&A)
#define pll(A) printf("%lld\n",A)
#else
#define makel(A) scanf("%I64d",&A)
#define pll(A) printf("%I64d\n",A)
#endif
template<typename C> void ma(C& a,C b){if(a<b)a=b;}
template<typename C> void mi(C& a,C b){if(a>b)a=b;}
#define MAX 100100
int n,v[MAX];
vector<int> d[MAX];
LL INF = 1e16;
void raz(LL &a,LL b){
  if(INF / a < b){
    a = INF;
  }else
    a*=b;
}
PLL dfs(int nr,int o){
  if(d[nr].size() == 1){
    return MP(LL(v[nr]),1ll);
  }
  LL m = INF;
  LL s = 1;
  R(i,d[nr].size()){
    if(d[nr][i] != o){
      PLL ak = dfs(d[nr][i],nr);
      mi(m,ak.FI);
      LL pom = ak.SE / __gcd(s,(LL)ak.SE); 
      raz(s,pom);
    }
  }
  m = m / s * s * (d[nr].size()-1);
  raz(s,d[nr].size()-1);
  //printf("%d %lld %lld\n",nr,m,s);
  return MP(m,s);
}
main(){
  make(n);
  LL all = 0;
  R(i,n){
    make(v[i]);
    all+=v[i];
  }
  R(i,n-1){
    int a,b;
    make(a);a--;
    make(b);b--;
    d[a].PB(b);
    d[b].PB(a);
  }
  d[0].PB(0);
  pll(all - dfs(0,0).FI);
}