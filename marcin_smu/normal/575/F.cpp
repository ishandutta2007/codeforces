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
#define SZ(x) ((int)(x).size())
#define db if(1)printf
template<typename C> void MA(C& a,C b){if(a<b)a=b;}
template<typename C> void MI(C& a,C b){if(a>b)a=b;}
int n;
main(){
  make(n);
  LL wyn = 0;
  int p;
  make(p);
  int k = p;
  R(i,n){
    int a,b;
    make2(a,b);
    int o1 = a - k;
    int o2 = p - b;
    if(k < a || b < p){
      wyn += max(o1,o2);
      int pom = p;
      p = min(k,b);
      k = max(a,pom);
    }else{
      p = max(a,p);
      k = min(b,k);
    }
  }
  printf("%lld\n",wyn);
}