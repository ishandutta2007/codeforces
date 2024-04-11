#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
 int T; scanf("%d",&T);
 int A[50];
 while(T--){
  int N; scanf("%d",&N);
  rep(i,N) scanf("%d",&A[i]);
  sort(A,A+N);
  bool ok=true;
  rep(i,N-1) if(A[i]+1<A[i+1]) ok=false;
  printf(ok ? "YES\n" : "NO\n");
 }
 return 0;
}