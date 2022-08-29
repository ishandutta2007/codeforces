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
template<typename C> void ma(C& a,C b){if(a<b)a=b;}
template<typename C> void mi(C& a,C b){if(a>b)a=b;}
int n,m,h;
map<int,int> s;
const int MAX = 1<<18;
int dp[MAX*2],il[MAX*2],a[MAX],b[MAX];
int kk,gl;
void dod(int nr=1,int pp=0,int kp=MAX-1){
  if(kk < pp)return;
  if(kk >= kp){
    il[nr]+=gl;
    dp[nr]+=gl;
    return;
  }
  dod(nr*2,pp,(pp+kp)/2);
  dod(nr*2+1,(pp+kp)/2+1,kp);
  dp[nr] = min(dp[nr*2],dp[nr*2+1]) + il[nr];
}
void add(int nr,int war){
  kk = nr;
  gl = war;
  dod();
}
main(){
  scanf("%d%d%d",&n,&m,&h);
  R(i,m)make(b[i]);
  R(i,n)make(a[i]);
  sort(b,b+m);
  set<int> skal;
  R(i,m){
    skal.insert(h-b[i]);
  }
  R(i,n){
    skal.insert(a[i]);
  }
  int i = 0;
  for(int pom:skal)s[pom] = i++;
  R(i,m){
    add(s[h-b[i]],-1);
  }
  R(i,m){
    add(s[a[i]],1);
  }
  int wyn = 0;
  if(dp[1] >= 0)wyn ++;
  R(i,n-m){
    add(s[a[i]],-1);
    add(s[a[i+m]],1);
    if(dp[1] >= 0)wyn ++;
    
  }
  
  printf("%d\n",wyn);
}