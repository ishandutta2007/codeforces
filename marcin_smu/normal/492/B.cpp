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
int n,t[1000],l;
main(){
  scanf("%d%d",&n,&l);
  R(i,n)make(t[i]);
  sort(t,t+n);
  int wyn = t[0]*2;
  R(i,n-1){
    if(t[i+1] - t[i] > wyn)
      wyn = t[i+1] - t[i];
  }
  wyn = max(wyn, 2*(l-t[n-1]));
  printf("%d.%d\n",wyn/2,5* (wyn%2));
}