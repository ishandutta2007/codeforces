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
#define db if(1)printf
template<typename C> void ma(C& a,C b){if(a<b)a=b;}
template<typename C> void mi(C& a,C b){if(a>b)a=b;}
#define MAX 1111
int n,m,t[MAX],w[MAX];
int cz[MAX];
main(){
  make2(n,m);
  R(i,n)make(w[i]);
  R(i,m){
    make(t[i]);
    t[i]--;
  }
  int k = 1,wyn=0,pom=0;
  R(i,n){
    k++;pom=0;
    R(j,m){
      if(i == t[j]){
        k++;
        wyn += pom;
        pom = 0;
      }else{
        if(cz[t[j]] != k)
          pom += w[t[j]];
        cz[t[j]] = k;
      }
    }
  }
  printf("%d\n",wyn);
}