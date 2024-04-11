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
#define MAX 200100
int n;
PI t[MAX*2];
int war[MAX];
main(){
  make(n);
  R(i,n){
    int a,b;
    make2(a,b);
    t[i*2] = MP(a-b,i+1);
    t[i*2+1] = MP(a+b,-i-1);
  }
  sort(t,t+n*2);
  int res = 1;
  R(i,n*2){
    PI ak = t[i];
    if(ak.SE < 0){
      res = max(res,war[-ak.SE]);
    }else
      war[ak.SE] = res+1;
  }
  printf("%d\n",res-1);
}