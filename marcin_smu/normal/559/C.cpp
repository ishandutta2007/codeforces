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
#define MAX 3011
int h,w;
int n;
#define MAX2 300000
LL sil[MAX2],odw[MAX2];
const int P = 1e9 + 7;
struct lam{
  int a,b;
  int wyn;
}l[MAX];
int il;
PI t[MAX];
LL dwu(int a,int b){
  return sil[a+b] * odw[a] %P * odw[b] % P;
}
int licz(int x,int y){
  LL res = 0;
  R(i,il){
    if(x >= l[i].a && y >= l[i].b)
      res += dwu(x-l[i].a,y-l[i].b) * l[i].wyn %P;
  }
  return res%P;
}
LL pot(LL a,int w){
  LL res = 1;
  while(w){
    if(w&1){
      res *= a;
      res %= P;
    }
    w/=2;
    a*=a;
    a%=P;
  }
  return res;
}
main(){
  sil[0] = 1;
  F(i,1,MAX2)sil[i] = sil[i-1] * i % P;
  R(i,MAX2)odw[i] = pot(sil[i],P-2);
  make2(h,w);
  make(n);
  l[0] = {1,1,1};
  il=1;
  R(i,n)
    make2(t[i].FI,t[i].SE);

  sort(t,t+n);
  R(i,n){
    int wyn = licz(t[i].FI,t[i].SE);
    l[il++] = {t[i].FI,t[i].SE,-wyn};
  }
  printf("%d\n",(licz(h,w)+P)%P);
}