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
#define db if(0)printf
template<typename C> void MA(C& a,C b){if(a<b)a=b;}
template<typename C> void MI(C& a,C b){if(a>b)a=b;}
#define MAX 201000
int n,m;
int k,q;
int wyn[MAX];
int x[MAX],y[MAX];
int X1[MAX],X2[MAX],Y1[MAX],Y2[MAX];
vector<int> pkty[MAX];
struct zap{
  int war,nr,pp,kp;
  void spr();
};
vector<zap> za[MAX];
int dp[MAX*3];
int nn;
int pp,kp;
int mi(int nr,int pk,int kk){
  if(pk > kp || kk < pp)return 1e9;
  if(pp <= pk && kk <= kp){
    return dp[nr];
  }
  return min(
    mi(nr*2,pk,(pk+kk)/2),
    mi(nr*2+1,(pk+kk)/2+1,kk)
  );
}
void add(int ak,int il){
  db("add %d %d\n",ak,il);
  ak += nn;
  dp[ak] = il;
  while(1){
    ak/=2;
    dp[ak] = min(dp[ak*2],dp[ak*2+1]);
    if(ak == 1)break;
  }
}
void zap::spr(){
  ::pp = pp;
  ::kp = kp;
  int pom = mi(1,0,nn-1);
  db("spr %d %d %d\n",nr,pom,war);
  if(pom >= war){
    db("OK\n");
    wyn[nr] = 1;
  }
}
void licz(){
  R(i,m)pkty[i].clear();
  R(i,m)za[i].clear();
  nn = 1;while(nn<=n)nn*=2;
  R(i,nn*2)dp[i] = -1;
  R(i,k)pkty[y[i]].PB(x[i]);
  R(i,q)za[Y2[i]].PB(zap{Y1[i],i,X1[i],X2[i]});
  R(i,m){
    R(j,pkty[i].size()){
      add(pkty[i][j],i);
    }
    R(j,za[i].size())
      za[i][j].spr();
  }
}
main(){
  make2(n,m);
  make2(k,q);
  R(i,k){
    make(x[i]);x[i]--;
    make(y[i]);y[i]--;
  }
  R(i,q){
    make2(X1[i],Y1[i]);X1[i]--;Y1[i]--;
    make2(X2[i],Y2[i]);X2[i]--;Y2[i]--;
  }
  licz();
  swap(n,m);
  R(i,k)swap(x[i],y[i]);
  R(i,q){
    swap(X1[i],Y1[i]);
    swap(X2[i],Y2[i]);
  }
  licz();
  R(i,q){
    puts(wyn[i]?"YES":"NO");
  }
}