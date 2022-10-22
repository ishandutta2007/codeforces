#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N,Q;
int A[100000];
int c;

int main(){
  scanf("%d%d",&N,&Q);
  rep(i,N) scanf("%d",&A[i]);
  c=0; rep(i,N) c+=A[i];
  while(Q--){
    int t; scanf("%d",&t);
    if(t==1){
      int x; scanf("%d",&x); x--;
      c-=A[x]; A[x]=1-A[x]; c+=A[x];
    }
    if(t==2){
      int k; scanf("%d",&k); k--;
      if(k<c) printf("1\n"); else printf("0\n");
    }
  }
  return 0;
}