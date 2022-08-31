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
#define maka2(A,B) scanf("%d%d",&A,&B)
#define db(A) printf("%s: %d\n",#A,A);
template<typename C> void ma(C& a,C b){if(a<b)a=b;}
template<typename C> void mi(C& a,C b){if(a>b)a=b;}
#define MAX 31
const int P = 1e9 + 7;
int n; 
LL pom[MAX][MAX];
struct m{
  LL t[MAX][MAX];
  void id(){
    R(i,n)R(j,n)t[i][j] = (i==j);
  }
  void operator*=(m& b){
    R(i,n)R(j,n)pom[i][j] = 0;
    R(i,n)R(j,n)R(k,n)
      pom[i][k] += t[i][j] * b.t[j][k] % P;
    R(i,n)R(j,n)
      t[i][j] = pom[i][j] % P;
  }
  m(){};
  m(m b,int w){
    id();
    while(w){
      if(w&1)
        *this*=b;
      w/=2;
      b*=b;
    }
  }
//   void pri(){
//     R(i,n){R(j,n)printf("%d ",t[i][j]);puts("");}
//     puts("");
//   }
}obr,nl,ak;
vector<m> d;
LL mm;
LL pw[MAX];
LL wyn[MAX];
int k;
vector<int> roz;
main(){
  scanf("%lld%d",&mm,&k);
  while(mm){
    roz.PB(mm%k);
    mm/=k;
  }
  n = k+1;
  R(i,k)obr.t[i][(i+1)%k] = 1;
  obr.t[k][k] = 1;
  R(i,k+1){
    nl.t[0][i] = 1;
    nl.t[i][i] = 1;
  }
  d.PB(nl);
  d[0] *= obr;
  F(i,1,roz.size()){
    d.PB(m(d[i-1],k));
    d[i] *= obr;
  }
  R(i,n)wyn[i] = 1;
  for(int ii = roz.size()-1;ii>=0;ii--){
    m pom(d[ii],roz[ii]);
    R(i,n)pw[i] = 0;
    R(i,n)R(j,n)pw[j] += wyn[i] * pom.t[i][j] % P;
    R(i,n)wyn[i] = pw[i] % P;
  }
  printf("%lld\n",wyn[k]);
}