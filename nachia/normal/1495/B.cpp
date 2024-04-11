#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
vector<int> A;

int leftc(int s){
  int c=1;
  while((s<1)?false:(A[s-1]<A[s])){ s--; c++; }
  return c;
}
int rightc(int s){
  int c=1;
  while((s>N-2)?false:(A[s]>A[s+1])){ s++; c++; }
  return c;
}

int main(){
  scanf("%d",&N);
  A.resize(N); rep(i,N) scanf("%d",&A[i]);
  vector<int> V;
  int maxlen=0;
  int ans=0;
  for(int i=1; i<N-1; i++) if(A[i-1]<A[i]&&A[i]>A[i+1]){
    int l=leftc(i), r=rightc(i);
    maxlen=max(maxlen,l);
    maxlen=max(maxlen,r);
  }
  int maxlenc=0;
  for(int i=1; i<N-1; i++) if(A[i-1]<A[i]&&A[i]>A[i+1]){
    int l=leftc(i), r=rightc(i);
    if(maxlen==l) maxlenc++;
    if(maxlen==r) maxlenc++;
    if(l==r) if(l==maxlen) ans=1;
  }
  if(leftc(N-1)==maxlen) ans=0;
  if(rightc(0)==maxlen) ans=0;
  if(maxlenc!=2) ans=0;
  if(maxlen%2!=1) ans=0;
  printf("%d\n",ans);
  return 0;
}