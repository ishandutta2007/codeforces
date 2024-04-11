#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(UL i=0; i<(n); i++)

UL N;
UL A[1000];
UL S[1001]={};
UL P;
vector<UL>ans;

UL MEX(){
 rep(i,N+1) if(!S[i]) return i;
}
void Operation(UL p, UL mex=~0u){
 S[A[p]]--;
 if(!~mex) mex=MEX();
 A[p]=mex;
 S[A[p]]++;
 ans.push_back(p);
}
bool OK(){
 rep(i,N-1) if(A[i]>A[i+1]) return false;
 return true;
}

void Case(){
 scanf("%u",&N);
 rep(i,N) scanf("%u",&A[i]);
 rep(i,N+1) S[i]=0;
 P=N;
 ans.clear();
 rep(i,N) S[A[i]]++;
 while(P!=0){
  UL mex=MEX();
  UL p=mex; if(mex>=P){ p--; P--;}
  Operation(p,mex);
 }
 printf("%u\n",ans.size());
 rep(i,ans.size()){
  if(i) printf(" ");
  printf("%u",ans[i]+1);
 } printf("\n");
}

int main() {
 UL T; scanf("%u", &T);
 rep(t,T) Case();
 return 0;
}