#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N,D; LL M;
LL A[100000];
LL Sl[100001];
LL Sr[100001];
vector<LL> low;

int main() {
 scanf("%d%d%lld",&N,&D,&M);
 rep(i,N) scanf("%d",&A[i]);
 sort(A,A+N);

 Sr[0]=0; for(int i=1; i<=N; i++) Sr[i] = Sr[i-1]+A[N-i];

 rep(i,N) if(A[i]<=M) low.push_back(A[i]);
 reverse(low.begin(),low.end());

 Sl[0]=0; for(int i=1; i<=low.size(); i++) Sl[i] = Sl[i-1]+low[i-1];

 LL ans=0, sumsmall=0;
 rep(p,low.size()+1){
  int n = N-p; n = (n+D)/(D+1);
  if(n + low.size() > N) continue;
  LL tmp = Sl[p] + Sr[n];
  ans = max(ans,tmp);
 }

 printf("%lld\n",ans);

 return 0;
}