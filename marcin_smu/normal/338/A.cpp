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
int k,n,m;
const int P = 1e9 + 9;
LL po(LL a,int w){
  LL r = 1;
  while(w){
    if(w&1){
      r*=a;
      r%=P;
    }
    w/=2;
    a*=a;
    a%=P;
  }
  return r;
}
main(){
  scanf("%d%d%d",&n,&m,&k);
  LL zle = n-m;
  LL pom = zle * (k-1);
  LL x = max(0ll,m - pom) / k;
  LL wyn = (po(2,x+1) - 2) * k % P;
  wyn += m-x*k;
  printf("%lld\n",(wyn%P+P)%P);
}