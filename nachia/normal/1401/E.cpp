#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

struct RSQ{
 int N;
 vector<int> V;
 void init(int n){
  N=1; while(N<n) N<<=1;
  V.assign(N*2,0);
 }
 void upd(int p,int v){
  p += N; V[p]=v;
  while(p!=1){
   p>>=1;
   V[p] = V[p<<1] + V[(p<<1)+1];
  }
 }
 int query(int l,int r,int a=-1,int b=-1,int i=-1){
  if(i==-1){ a=0; b=N; i=1; }
  if(r<=a || b<=l) return 0;
  if(l<=a && b<=r) return V[i];
  int ql = query(l,r,a,(a+b)>>1,i<<1);
  int qr = query(l,r,(a+b)>>1,b,(i<<1)+1);
  return ql + qr;
 }
};

int N,M;
vector<pair<int,int>> Y[1000002];
vector<pair<int,int>> X[1000001];

int main() {
 scanf("%d%d",&N,&M);
 rep(i,N){
  int y,lx,rx; scanf("%d%d%d",&y,&lx,&rx);
  Y[lx].push_back({y,1});
  Y[rx+1].push_back({y,0});
 }
 Y[0].push_back({0,1});
 Y[1].push_back({1000000,1});
 rep(i,M){
  int y,lx,rx; scanf("%d%d%d",&y,&lx,&rx);
  X[y].push_back({lx,rx+1});
 }
 X[0].push_back({0,1000001});
 X[1000000].push_back({0,1000001});

 RSQ Q; Q.init(1000001);
 Q.upd(0,1); Q.upd(1000000,1);
 LL ans = 0;
 rep(i,1000001){
  for(auto p:Y[i]){ Q.upd(p.first,p.second); ans-=p.second; }
  for(auto p:X[i]){ ans += Q.query(p.first,p.second)-1; }
 }
 printf("%lld\n",ans+1);

 return 0;
}