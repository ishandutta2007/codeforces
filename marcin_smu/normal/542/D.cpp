#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PI;
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
LL n;
map<LL,vector<LL> >m;
void add(LL a,LL d){
//   printf("%lld %lld\n",a,d);
  m[d].PB(a);
}
void spr(LL a){
//   printf("spr %lld\n",a);
  if(a<=2)return;
  a--;
  for(LL i=2;i*i<=a;i++){
    if(a%i == 0){
      LL pom = a;
      while(a%i == 0)a/=i;
      if(a != 1)return;
      add(pom+1,i);
      return;
    }
  }
  add(a+1,a);
}
map<LL,LL> dp;
main(){
  scanf("%lld",&n);
  LL i;
  for(i=1;i*i<n;i++){
    if(n%i==0){
      spr(i);
      spr(n/i);
    }
  }
  if(i*i == n)spr(i);
  dp[1]=1;
  for(auto x : m){
    vector<PI> to_add;
    for(LL a : x.SE){
      for(auto b : dp){
        if(1e13 / a > b.FI)
          to_add.PB(MP(a*b.FI,b.SE));
      }
    }
    R(i,to_add.size()){
      if(n%to_add[i].FI == 0){
        dp[to_add[i].FI] += to_add[i].SE;
      }
    }
  }
  printf("%lld\n",dp[n]);
}