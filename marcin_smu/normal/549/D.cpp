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
template<typename C> void maxi(C& a,C b){if(a<b)a=b;}
template<typename C> void mini(C& a,C b){if(a>b)a=b;}
#define MAX 101
int n,m;
char z[MAX][MAX];
int sum[MAX][MAX];
main(){
  make2(n,m);
  R(i,n)scanf("%s",z[i]);
  int wyn = 0;
  FD(i,n)FD(j,m){
    int ma = z[i][j] == 'W' ? 1 : -1;
    if(sum[i][j] != ma){
      wyn ++;
      int il = ma - sum[i][j];
      R(ii,i+1)R(jj,j+1)
        sum[ii][jj] += il;
    }
  }
  printf("%d\n",wyn);
}