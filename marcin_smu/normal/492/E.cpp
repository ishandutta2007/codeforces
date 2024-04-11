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
#define MAX 1001000
int n,m,dx,dy;
int wyn = 0;
int il[MAX];
int g[MAX];
main(){
  scanf("%d%d%d%d",&n,&m,&dx,&dy);
  int akx = 0;
  int aky = 0;
  R(i,n){
    g[akx] = aky;
    akx+=dx;if(akx >= n)akx -= n;
    aky+=dy;if(aky >= n)aky -= n;
  }
  R(i,m){
    int a,b;
    scanf("%d%d",&a,&b);
    il[(n+b-g[a])%n]++;
  }
  int wyn = 0,gd = 0;
  R(i,n){
    if(il[i] > wyn){
      wyn = il[i];
      gd = i;
    }
  }
  printf("%d %d\n",0,gd);
}