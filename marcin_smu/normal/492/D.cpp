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
#ifdef LOCAL
#define makel(A) scanf("%lld",&A)
#define pll(A) printf("%lld\n",A)
#else
#define makel(A) scanf("%I64d",&A)
#define pll(A) printf("%I64d\n",A)
#endif
template<typename C> void ma(C& a,C b){if(a<b)a=b;}
template<typename C> void mi(C& a,C b){if(a>b)a=b;}
#define MAX 2000000
int n,x,y;
int wyn[MAX];
main(){
  scanf("%d%d%d",&n,&x,&y);
  int a=0,b=0;
  while(a < x && b < y){
    LL aa = (LL)(a+1) * y;
    LL bb = (LL)(b+1) * x;
    if(aa < bb){
      wyn[a+b] = 0;
      a++;
    }else if(aa == bb){
      wyn[a+b] = wyn[a+b+1] = 1;
      a++;
      b++;
    }else{
      wyn[a+b] = 2;
      b++;
    }
  }
  while(n--){
    make(a);a--;
    a%=x+y;
    if(wyn[a] == 0)puts("Vanya");
    if(wyn[a] == 1)puts("Both");
    if(wyn[a] == 2)puts("Vova");
  }
}