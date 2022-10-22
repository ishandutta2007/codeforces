#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
int CB[300000];
int CN[300000];
int Bbuf=0,Nbuf=0;

int F(int cn,int cb){
 int ans=0;
 rep(i,N){
  ans=max(ans,abs(cn-CN[i]));
  ans=max(ans,abs(cb-CB[i]));
  ans=max(ans,abs((cn-CN[i])-(cb-CB[i])));
 }
 return ans;
}

int FF(int cb){
 int lN,rN; lN=-1; rN=500010; if(cb==0) lN=0;
 while(lN+2<rN){
  int m1N = (lN+lN+rN)/3, m2N = (lN+rN+rN)/3;
  if(F(m1N,cb) < F(m2N,cb)) rN=m2N; else lN=m1N;
 }
 Nbuf = lN+1;
 return F(Nbuf,cb);
}

int main() {
 cin>>N;
 rep(i,N){
  CB[i]=CN[i]=0;
  string S; cin>>S;
  for(char c:S) if(c=='B') CB[i]++; else if(c=='N') CN[i]++;
 }

 int lB,rB; lB=-1; rB=500010;
 while(lB+2<rB){
  int m1B = (lB+lB+rB)/3, m2B = (lB+rB+rB)/3;
  if(FF(m1B) < FF(m2B)) rB=m2B; else lB=m1B;
 }
 Bbuf = lB+1;
 FF(Bbuf);

 printf("%d\n",F(Nbuf,Bbuf));
 rep(i,Bbuf) printf("B");
 rep(i,Nbuf) printf("N");
 printf("\n");

 return 0;
}