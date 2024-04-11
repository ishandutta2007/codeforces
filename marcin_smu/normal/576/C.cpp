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
#define MAX 1000010
int n;
int x[MAX],y[MAX];
vector<int> t[1001][1001];
void dod(int a,int b){
  R(i,SZ(t[a][b])){
    printf("%d ",t[a][b][i]+1);
  }
}
main(){
  make(n);
  R(i,n){
    int x,y;
    make(x);if(!x)x++;
    make(y);if(!y)y++;
    t[(x-1)/1000][(y-1)/1000].PB(i);
  }
  R(i,1000){
    if(i&1){
      R(j,1000)
        dod(i,j);
    }else{
      FD(j,1000)
        dod(i,j);
    }
  }
  puts("");
}