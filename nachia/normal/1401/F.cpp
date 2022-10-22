#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

struct XRSQ{
 int N,dN;
 vector<LL> V;
 int X;
 void init(int n){
  dN=n;
  N=1<<n; V.resize(N*2);
  X=0;
 }
 void upd(int p, LL v){
  p^=X;
  p+=N; V[p]=v;
  while(p!=1){
   p>>=1;
   V[p] = V[p<<1]+V[(p<<1)+1];
  }
 }
 void xorx(int x){ X^=x; }
 LL query(int l,int r,int a=-1,int b=-1,int d=-1,int i=-1){
  if(i==-1){ a=0; b=N; d=dN; i=1; }
  if(r<=a || b<=l) return 0;
  if(l<=a && b<=r) return V[i+((a^X)>>d)];
  LL q1 = query(l,r,a,(a+b)>>1,d-1,i<<1);
  LL q2 = query(l,r,(a+b)>>1,b,d-1,i<<1);
  return q1+q2;
 }
};

int main() {
 int N,Q; scanf("%d%d",&N,&Q);
 XRSQ G; G.init(N);
 rep(i,1<<N) scanf("%d",&G.V[i+G.N]);
 for(int i=G.N-1; i>=1; i--) G.V[i]=G.V[i<<1]+G.V[(i<<1)+1];
 while(Q--){
  int c; scanf("%d",&c);
  if(c==1){
   int x,k; scanf("%d%d",&x,&k); x--;
   G.upd(x,k);
  }
  if(c==2){
   int k; scanf("%d",&k);
   G.xorx((1<<k)-1);
  }
  if(c==3){
   int k; scanf("%d",&k);
   G.xorx(1<<k);
  }
  if(c==4){
   int l,r; scanf("%d%d",&l,&r); l--;
   printf("%lld\n",G.query(l,r));
  }
 }
 
 return 0;
}