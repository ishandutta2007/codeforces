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
#define MAX 1000001
int n;
int t[MAX];
int wyn[MAX];
int np[MAX];
main(){
  make(n);
  R(i,n){
    make(t[i]);
    wyn[t[i]] ++;
  }
  int res = 1;
  F(i,2,MAX){
    if(np[i] == 0){
      for(int j = 1;i*j < MAX;j ++){
        if(np[i*j] == 0)
          np[i*j] = i;
      }
    }
    int ak = i;
    int ww = 0;
    while(ak !=1){
      int pom = np[ak];
      MA(ww, wyn[i/pom]);
      while(ak % pom == 0)
        ak/=pom;
    }
    wyn[i] += ww;
    MA(res,wyn[i]);
  }
  printf("%d\n",res);
}