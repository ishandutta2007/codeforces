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
int n;
char z[MAX];
int t[MAX][MAX];
int il[MAX];
main(){
  make(n);
  R(i,n){
    scanf("%s",z);
    R(j,n){
      t[i][j] = z[j] - '0';
    }
  }
  R(i,n)make(il[i]);
  int x =1;
  vector<int> wyn;
  while(x){
    x = 0;
    R(i,n){
      if(il[i] == 0){
        wyn.PB(i);
        R(j,n){
          il[j] -= t[i][j];
        }
        x = 1;
      }
    }
  }
  printf("%d\n",SZ(wyn));
  R(i,SZ(wyn)){
    printf("%d ",wyn[i]+1);
  }
  puts("");
}