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
#define MAXX 1100001
#define MAX 200001
int n,m;
struct node{
  LL suf,pref,sum,war;
  void scal(node a,node &b){
    sum = a.sum + b.sum;
    suf = max(a.suf+b.sum,b.suf);
    pref = max(a.sum+b.pref,a.pref);
    war = max(a.war,max(b.war,a.suf+b.pref));
  }
  void set(LL a){
    //printf("%lld ",a);
    suf = pref = sum = a;
    war = 0;
  }
  void wys(){
    printf("%lld %lld %lld %lld\n",pref,suf,war,sum);
  }
}dp[MAXX*2],gl;
int nn,pk,kk;
void licz(int nr = 1,int pp = 0, int kp = nn-1){
  if(pk > kp || kk < pp) return;
  if(pk <= pp && kp <= kk){
    //dp[nr].wys();
    gl.scal(gl,dp[nr]);
    return;
  }
  licz(nr*2,pp,(pp+kp)/2);
  licz(nr*2+1,(pp+kp)/2+1,kp);
}
LL d[MAX],h[MAX];
main(){
  make2(n,m);
  R(i,n){
    scanf("%lld",&d[i]);
    d[i+n] = d[i];
  }
  R(i,n){
    scanf("%lld",&h[i]);
    h[i]*=2;
    h[i+n] = h[i];
  }
  n*=2;
  nn = 1;while(nn<=n*2)nn*=2;
  R(i,n){
    dp[i*2+nn].set(2*h[i]);
    dp[i*2+nn+1].set(d[i] - h[i] - h[i+1]);
  }
  //printf("\n");
  FD(i,nn-1)dp[i].scal(dp[i*2],dp[i*2+1]);
  while(m--){
    int a,b;
    make2(a,b);
    gl.set(LL(-1e18));
    if(b<a)b+=n/2;
    pk = b*2;
    kk = n+a*2-4;
   // printf("%d %d\n",pk,kk);
    licz();
    printf("%lld\n",gl.war);
  }
}