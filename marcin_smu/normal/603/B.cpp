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
int p,k;
const int mod = 1e9 + 7;
LL pot(LL a,LL k){
  LL res = 1;
  while(k){
    if(k&1){
      res *= a;
      res %= mod;
    }
    a*=a;
    a%=mod;
    k/=2;
  }
  return res;
}
main(){
  make2(p,k);
  if(k == 0){
    printf("%lld\n",pot(p,p-1));
    return 0;
  }
  if(k == 1){
    printf("%lld\n",pot(p,p));
    return 0;
  }
  int rzad = 0;
  LL kk = 1;
  do{
    kk *= k;
    kk %= p;
    rzad++;
  }while(kk != 1);
  printf("%lld\n",pot(p,(p-1)/rzad));
}