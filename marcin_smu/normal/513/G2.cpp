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
#define MAX 1000
int n,k;
D w[MAX],w2[MAX];//,m[MAX][MAX];
int odb(int p,int k,int c){
  if(c < p || c > k)return c;
  return k+p-c;
}
int get(int i,int j){
  return i*n+j;
}
int t[MAX];
main(){
  make(n);make(k);
  R(i,n)make(t[i]);
  R(i,n)R(j,i){
    if(t[i] > t[j])
      w[get(i,j)] = 1.;
    else
      w[get(j,i)] = 1.;
  }
  D pom = n*(n+1)/2;
  R(_,k){
    R(i,n)R(j,i+1){
      R(ii,n)R(jj,n){
        int iii = odb(j,i,ii);
        int jjj = odb(j,i,jj);
        w2[get(ii,jj)] += w[get(iii,jjj)] / pom;
      //    m[get(ii,jj)][get(iii,jjj)] += pom;
    //    m[get(iii,jjj)][get(ii,jj)] += pom;
      }
    }
    R(i,n*n){
      w[i] = w2[i];
      w2[i] = 0;
    }
  }
  D wyn = 0,wyn2 =0;
  R(i,n)R(j,n){
    if(i < j)
      wyn += w[get(i,j)];
  }
  printf("%.10f\n",wyn);
}