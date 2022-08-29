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
#define MAX 200901
int n;
int x[MAX];
main(){
  make(n);
  R(i,n){
    make(x[i]);
    x[i] -= n-i-1;
  }
  sort(x,x+n);
  R(i,n-1){
    if(x[i] == x[i+1]){
      puts(":(");
      return 0;
    }
  }
  R(i,n){
    x[i] += n-i-1;
  }
  R(i,n){
    printf("%d ",x[i]);
  }
  puts("");
}