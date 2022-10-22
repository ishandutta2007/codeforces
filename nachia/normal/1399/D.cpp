#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
vector<int> A;
vector<int> B;
vector<int> ans;
int K;

void loop(){
 A.clear(); B.clear(); ans.clear();
 K=0;
 scanf("%d",&N);
 scanf(" ");
 rep(i,N){
  char c; scanf("%c",&c);
  if(c=='0'){
   if(A.empty()){ K++; A.push_back(K); }
   ans.push_back(A.back());
   B.push_back(A.back()); A.pop_back();
  }
  else{
   if(B.empty()){ K++; B.push_back(K); }
   ans.push_back(B.back());
   A.push_back(B.back()); B.pop_back();
  }
 }
 printf("%d\n",K);
 rep(i,ans.size()){ if(i) printf(" "); printf("%d",ans[i]); }
 printf("\n");
}

int main() {
 int T; scanf("%d",&T);
 while(T--) loop();
 return 0;
}