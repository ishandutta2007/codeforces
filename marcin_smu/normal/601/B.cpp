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
#define MAX 100010
int n,q;
int t[MAX];
void test(){
  int a,b;
  make2(a,b);
  debug("test",a,b);
  a--;b--;
  LL war = 0;
  LL res = 0;
  vector<PII> stos;
  F(i,a,b){
    debug(t[i]);
    int sze = 1;
    while(SZ(stos) > 0 && stos.back().FI < t[i]){
      war -= stos.back().FI * 1ll * stos.back().SE;
      sze += stos.back().SE;
      stos.pop_back();
      debug("tu");
    }
    debug(t[i],sze);
    stos.PB({t[i],sze});
    war += t[i] * 1ll * sze;
    res += war;
  }
  printf("%lld\n",res);
}
main(){
  make2(n,q);
  int ost;
  make(ost);
  R(i,n - 1){
    int pom;
    make(pom);
    t[i] = abs(pom - ost);
    ost = pom;
  }
  while(q--)test();
}