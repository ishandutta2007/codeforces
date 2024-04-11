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
#define MAX 41
int n,x;
int t[MAX][MAX];
int w[MAX],tt[MAX];
int wyn;
inline int zn(int a){
  return a?-1:1;
}
int licz3(){
  int wyn1=tt[x-1],wyn2=tt[x-1]*-1;
  R(i,x-1){
    wyn1 += abs(tt[i] + tt[x+i]);
    wyn2 += abs(tt[i] - tt[x+i]); 
  }
  return max(wyn1,wyn2);
}
void licz2(){
  int war = 0;
  F(i,x,n)w[i] = w[i-x] ^ w[x-1];
  R(i,n)war += t[x-1][i] * zn(w[i]);
 // R(i,n)printf("%d ",w[i]);
 // printf("\n");
  R(i,x-1){
    R(j,n){
      tt[j] = t[i][j] + t[i+x][j] * zn(w[j]);
    }
    int pom = licz3();
    war += pom;
  //  printf("%d ",pom);
  }
 // printf("\n%d\n",war);
  if(war > wyn)
    wyn = war;
}
void licz(int nr){
  if(nr == x){
    licz2();
    return;
  }
  w[nr] = 0;
  licz(nr+1);
  w[nr] = 1;
  licz(nr+1);
}
main(){
  make(n);x=(n+1)/2;
  R(i,n)R(j,n){
    make(t[i][j]);
    wyn += t[i][j];
  }
  licz(0);
  printf("%d\n",wyn);
}