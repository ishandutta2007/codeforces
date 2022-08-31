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

void res(bool x){
  puts(x ? "Nicky":"Kevin");
  exit(0);
}
int n,k;
map<int,int> pam;
int nib(int a){
  auto x = pam.find(a);
  if(x!=pam.end())return x->SE;
  int res;
  if(a%2 == 1){
    if(a <= 3)
      res = 1;
    else
      res = 0;
  }else{
    int w1 = nib(a-1);
    int w2 = nib(a/2);
    res = 0;
    while(res == w1 || res == w2)res++;
  }
  pam[a] = res;
  return res;
}
// int t[501];
main(){
//   t[0] = 0;
//   F(i,1,301){
//     R(res,3){
//       t[i] = res;
//       if(res != t[i-1] && (i%2 == 1 || res != t[i/2])){
//         break;
//       }
//     }
//     assert(nib(i) == t[i]);
//   }
  make2(n,k);
  if(k%2 == 0){
    int il1 = 0,il2 = 0;
    R(i,n){
      int pom;
      make(pom);
      if(pom == 2)
        il2 ++;
      else if(pom == 1 || pom % 2 == 0)
        il1 ++;
    }
    res(il1%2 == 0 && il2%2 ==0);
  }else{
    int x = 0;
    R(i,n){
      int pom;
      make(pom);
      x ^= nib(pom);
    }
    res(x == 0);
  }
}