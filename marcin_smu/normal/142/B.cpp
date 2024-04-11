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
int n,m;
main(){
  make2(n,m);
  if(n==1 || m==1)printf("%d\n",n*m);
  else{
    if(n == 2 || m == 2){
      int wyn = n*m/8 * 4;
      n%=4;
      m%=4;
      printf("%d\n",wyn + min(4,n*m));
    }else
      printf("%d\n",(n*m+1)/2);
  }
}