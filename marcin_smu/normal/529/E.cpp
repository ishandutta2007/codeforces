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
int n,k;
map<int,int> m;
void test(){
  int x;
  make(x);
  int wyn = k+1;
  for(auto v:m){
    int pom = x - v.FI;
    auto xx = m.find(pom);
    if(xx == m.end())continue;
    MI(wyn,v.SE + xx->SE);
  }
  if(wyn == k+1)
    printf("-1\n");
  else
    printf("%d\n",wyn);
}
main(){
  make2(n,k);
  R(_,n){
    int pom;
    make(pom);
    R(i,k+1){
      auto xx = m.find(pom*i);
      if(xx == m.end())
        m[pom*i] = i;
      else
        m[pom*i] = min(xx->SE,i);
    }
  }
  int _;
  make(_);
  while(_--)test();
}