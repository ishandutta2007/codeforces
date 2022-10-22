#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
int A[100000];
int B[100000];

void loop(){
 scanf("%d",&N);
 rep(i,N) scanf("%d",&A[i]);
 int m = A[0]; rep(i,N) if(m>A[i]) m=A[i];
 rep(i,N) B[i]=A[i]; sort(B,B+N);
 bool ok=true;
 rep(i,N) if(A[i]%m!=0) if(A[i]!=B[i]) ok=false;
 printf(ok?"YES\n":"NO\n");
}

int main() {

 int T; scanf("%d",&T);
 while(T--){
  loop();
 }

 return 0;
}