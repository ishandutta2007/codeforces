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
template<typename C> void ma(C& a,C b){if(a<b)a=b;}
template<typename C> void mi(C& a,C b){if(a>b)a=b;}
#define MAX 100001
int n;
int a[MAX],b[MAX];
struct lin{
  LL a,b;
  int pocz;
  lin(LL a,LL b):a(a),b(b){
    //b = war - x * a;
    pocz = 0;
  }
  LL war(LL x){
//     printf("war %lld\n",a*x+b);
    return a*x+b;
  }
  LL warp(){
    return war(pocz);
  }
//   void wys(){
//     printf("%d\n",pocz);
//     printf("%lld %lld %d\n",a,b,pocz);
//   }
};
deque<lin> ot;
main(){
  make(n);
  R(i,n){
    make(a[i]);
  }
  R(i,n)make(b[i]);
  ot.PB(lin(b[0],0));
  F(i,1,n){
    
    deque<lin>::iterator pom = ot.begin();pom++;
    while(pom != ot.end() && pom->pocz <= a[i]){
      //printf("pop_front\n");
      ot.pop_front();
      pom = ot.begin();
      pom++;
    }
//     puts("tu");
//     pom = ot.begin();
//     while(pom != ot.end()){
//       pom->wys();
//       pom++;
//     }
//     puts("");
    LL war = ot.front().war(a[i]);
//     printf("%d %lld\n",i,war);
    if(i == n-1){
      printf("%lld\n",war);
      return 0;
    }
    lin q(b[i],war);
//     q.wys();
    while(!ot.empty() && ot.back().warp() >= q.war(ot.back().pocz))
      ot.pop_back();
//     printf("siez %d\n",ot.size());
    if(ot.empty()){
      q.pocz = a[i];
      ot.PB(q);
    }else{
      int po = ot.back().pocz,ko = a[n-1]+2;
      while(po+1 < ko){
        int m = (po+ko)/2;
        if(q.war(m) >= ot.back().war(m))
          po = m;
        else
          ko = m;
      }
//       printf("%d %d\n",po,ko);
      if(ko <= a[n-1]){
        q.pocz = ko;
        ot.PB(q);
      }
    }
//     printf("tu\n");
  }
}