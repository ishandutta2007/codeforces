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
#define db(A) printf("%s: %d\n",#A,A);
template<typename C> void ma(C& a,C b){if(a<b)a=b;}
template<typename C> void mi(C& a,C b){if(a>b)a=b;}
#define MAX 1001
int n,m;
char z[MAX][MAX];
bool cz[MAX];
main(){
  make2(n,m);
  R(i,n)scanf("%s",z[i]);
  int wyn = 0;
  R(j,m){
    bool xx = 0;
    R(i,n-1){
      if(cz[i] == 0 && z[i][j] > z[i+1][j])
        xx = 1;
    }
    if(xx){
      wyn++;
    }else
      R(i,n-1)if(z[i][j] < z[i+1][j])cz[i] = 1;
  }
  printf("%d\n",wyn);
}