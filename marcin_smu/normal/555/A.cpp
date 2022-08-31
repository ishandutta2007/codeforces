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
int n,k;
PI t[MAX];
main(){
  make2(n,k);
  int ok = 0;
  R(i,k){
    int pom;make(pom);
    int ost = 1;
    R(i,pom){
      int pom2;
      make(pom2);
      if(pom2 == ost){
        ok++;
        ost++;
      }
    }
  }
  printf("%d\n",2*n-k-2*ok+1);
}