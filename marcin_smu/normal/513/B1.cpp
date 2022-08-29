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
#define MAX 100
int a[MAX];
void licz(int n,int ak,LL kt,int *t){
  if(n == 0)return;
  LL pom = 1ll<<(n-2);
  if(kt < pom){
    t[0] = ak;
    licz(n-1,ak+1,kt,t+1);
  }else{
    t[n-1] = ak;
    licz(n-1,ak+1,kt-pom,t);
  }
}
int n;
LL m;
main(){
  make(n);
  scanf("%lld",&m);
  licz(n,1,m-1,a);
  R(i,n)printf("%d ",a[i]);puts("");
}