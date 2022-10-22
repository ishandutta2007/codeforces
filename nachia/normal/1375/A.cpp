#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(UL i=0; i<(n); i++)

UL N;
int A[100];

void Case(){
 scanf("%u",&N);
 rep(i,N) scanf("%d",&A[i]);
 rep(i,N){
  if(i&1) A[i]=abs(A[i]);
  else A[i]=-abs(A[i]);
  if(i) printf(" ");
  printf("%d",A[i]);
 } printf("\n");
}

int main() {
 UL T; scanf("%u", &T);
 rep(t,T) Case();
 return 0;
}