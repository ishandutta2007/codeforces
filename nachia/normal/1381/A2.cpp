#include<bits/stdc++.h>
using namespace std;
using UL=unsigned int;
using LL=long long;
using ULL=unsigned long long;
#define rep(i,n) for(UL i=0; i<(n); i++)

UL N;
UL A[100000];
UL B[100000];

void Loop(){
 UL N; scanf("%u",&N);
 scanf(" "); rep(i,N){ char c; scanf("%c",&c); A[i]=c-'0'; }
 scanf(" "); rep(i,N){ char c; scanf("%c",&c); B[i]=c-'0'; }
 bool r = false;
 UL p=0, q=N-1;
 vector<UL> ans;
 rep(i,N){
  if(!r){
   if(A[p]==B[N-1-i]) ans.push_back(1);
   ans.push_back(N-i);
   r=true;
   p++;
  }
  else{
   if(A[q]!=B[N-1-i]) ans.push_back(1);
   ans.push_back(N-i);
   r=false;
   q--;
  }
 }
 printf("%u",ans.size());
 rep(i,ans.size()) printf(" %u",ans[i]);
 printf("\n");
}

int main(){
 UL T; scanf("%u",&T);
 rep(t,T) Loop();
 return 0;
}