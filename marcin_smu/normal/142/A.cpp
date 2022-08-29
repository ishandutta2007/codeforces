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
LL mi = 1e18;
LL ma = -1;
void spr(int n,int x){
  for(int i=1;i*i<=n;i++){
    if(n%i == 0){
      LL y = i;
      LL z = n/i;
      MI(mi,1ll * (y+2) * (z+2) * (x+1));
      MA(ma,1ll * (y+2) * (z+2) * (x+1));
    }
  }
}
int n;
main(){
  scanf("%d",&n);
  for(int i=1;i*i<=n;i++){
    if(n%i == 0){
      spr(n/i,i);
      spr(i,n/i);
    }
  }
  printf("%lld %lld\n",mi - n,ma - n);
}