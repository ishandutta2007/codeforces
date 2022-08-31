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
#define MAX 100010
int n;
bool cz[MAX];
LL wyn = 0;
LL t[MAX];
bool us(){
  LL sum = 0;
  int il = 0;
  bool res = 0;
  R(i,n)if(cz[i])sum+=t[i];
  R(i,n){
    if(cz[i]){
      il++;
      sum -= t[i];
      if(t[i] * il + sum < 0){
        wyn -= t[i] * il + sum;
        il--;
        cz[i] = 0;
        res = 1;
      }
    }
  }
  return res;
}
bool dod(){
  int il = 0;
  LL sum = 0;
  bool res = 0;
  R(i,n)if(cz[i])il++;
  FD(i,n){
    if(!cz[i]){
      if(t[i] * (il+1) + sum > 0){
        wyn += t[i] * (il+1) + sum;
        il++;
        cz[i] = 1;
        res = 1;
      }
    }
    if(cz[i]){
      il--;
      sum += t[i];
    }
  }
  return res;
}
main(){
  make(n);
  R(i,n){
    cz[i] = 1;
    scanf("%lld",&t[i]);
    wyn += t[i]*(i+1);
  }
  bool x = 1;
  while(x){
    x=0;
    if(us())x=1;
    if(dod())x=1;
  }
  printf("%lld\n",wyn);
}