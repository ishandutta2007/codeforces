#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PI;
typedef long long LL;
typedef pair<LL,LL> PLL;
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
#define MAX 100001
int n;
int t[MAX];
LL sp[MAX];
LL res = 0;
PLL licz(int po,int ko){
  LL sum = 0;
  int wyn = 0;
  int ak = 0;
  int naj = 0;
  int se = 0;
  F(i,po,ko){
    sum += t[i];
    if(t[i]&1){
      ak++;
      sum --;
    }else{
      ak--;
    }
    if(se < ak)se = ak;
    if(wyn < ak - naj) wyn = ak - naj;
    if(ak < naj)naj = ak;
  }
  MA(res,sum + wyn);
  return MP(sum + ak-naj, sum + se);
}
main(){
  make(n);n--;
  R(i,n)make(t[i]);
  int os = 0;
  LL sum = 0;
  LL aks = 0;
  LL naj = 0;
  R(i,n+1){
    if(t[i] == 1 || i == n){
      PLL pom = licz(os,i);
      MA(res,sum + pom.SE);
      sum = max(sum + aks + 1, pom.FI + 1);
      aks = 0;
      os = i+1;
    }else
      aks += t[i];if(t[i]%2 == 0)aks --;
  }
  printf("%lld\n",res);
}