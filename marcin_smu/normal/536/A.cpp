#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PI;
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
#define db if(1)printf
template<typename C> void MA(C& a,C b){if(a<b)a=b;}
template<typename C> void MI(C& a,C b){if(a>b)a=b;}
int a,b,n;
LL kt(LL i){
  return a + (i-1)*b;
}
int l,t,il;
bool spr(LL m){
  LL all = (m-l+1) * (kt(l) + kt(m)) /2;
  LL ost = kt(m);
  return (all+il-1)/il <= t && ost <= t;
}
main(){
  make2(a,b);
  make(n);
  R(i,n){
    make2(l,t);
    make(il);
    LL po = l-1,ko = 1e7;
    while(po + 1 < ko){
      LL m = po+ko >> 1;
      if(spr(m))
        po = m;
      else
        ko = m;
    }
    if(po == l-1)
      puts("-1");
    else
      printf("%lld\n",po);
  }
}