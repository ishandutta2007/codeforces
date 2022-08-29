#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
typedef long double D;
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

int n,m;
D dp[101][101001];
main(){
  make2(n,m);
  dp[0][0] = 1;
  int moj = 0;
  R(i,n){
    int pom;
    make(pom);
    pom--;
    moj += pom;
    D sum = 0;
    D xxx = 0;
    R(j,n*m){
      sum += dp[i][j];
      if(j >= m)
        sum -= dp[i][j-m];
      if(j >= pom)
        dp[i+1][j] = (sum - dp[i][j - pom])/ (m - 1);
      else
        dp[i+1][j] = sum / (m - 1); 
      xxx += dp[i+1][j];
    }
    debug(xxx);
  }
  D res = 0;
  R(i,moj){
    res += dp[n][i];
  }
  printf("%.12lf\n", double(1 + res*(m-1)));
}