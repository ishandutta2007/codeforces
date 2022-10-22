#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
int u,v;
int A[100];

int main(){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d%d",&N,&u,&v);
    rep(i,N) scanf("%d",&A[i]);
    int ans=2000000000;
    rep(i,N-1){
      if(A[i]==A[i+1]){
        ans=min(ans,v+v);
        ans=min(ans,u+v);
      }
      if(abs(A[i]-A[i+1])==1){
        ans=min(ans,u);
        ans=min(ans,v);
      }
      if(abs(A[i]-A[i+1])>=2){
        ans=0;
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}