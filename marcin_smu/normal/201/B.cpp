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
#define MAX 1010
int n,m;
int t[MAX][MAX];
int x;
LL kw(LL a){
  return a*a;
}
LL szu(int i){
  if(i == 2){
    LL wyn = 0;
    R(i,n)R(j,m)wyn += t[i][j] * kw(4*i-4*x+2);
    return wyn;
  }
  int po = 0,ko = n+1;
  while(po + 1 < ko){
    int m = (po + ko) / 2; 
    x = m-1;
    LL w1 = szu(2);
    x = m;
    LL w2 = szu(2);
    if(w1 <= w2){
      ko = m;
    }else
      po = m;
  }
  x = po;
  return szu(2);
}
main(){
  make2(n,m);
  R(i,n)R(j,m)make(t[i][j]);
  //n = m = 1000;
  //R(i,n)R(j,m)t[i][j] = rand();//make(t[i][j]);
  LL wyn = szu(0);
  int xx = x;
  R(i,max(n,m))R(j,i)swap(t[i][j],t[j][i]);
  swap(n,m);
  printf("%lld\n",wyn+szu(0));
  printf("%d %d\n",xx,x);
}