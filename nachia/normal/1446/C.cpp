#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
vector<int> A;

int Solve(int l,int r,int pl,int pr,int d){
  int outer=pl+pr;
  if(r-l==0) return outer;
  if(r-l==1) return outer+1;
  int dp = d-1;
  int newl = l; if((A[l]&((1<<d)-1))==0) newl++;
  vector<int> m(d,newl);
  vector<int> dm(d+1,0); if(newl!=l) dm[0]=1;
  for(int i=r-1; i>=newl; i--){
    while(!(A[i]&(1<<dp))){ m[dp]=i+1; dp--; }
    dm[dp+1]=1;
  }
  m.push_back(r);
  rep(i,d) dm[i+1]+=dm[i];
  int ans=0;
  rep(i,d) ans=max(ans,
    Solve(
      m[i],
      m[i+1],
      (dm[i]!=0)?1:0,
      dm[d]-dm[i+1],
      i
    )
  );
  return ans+outer;
}

int main(){
  cin>>N;
  A.resize(N); rep(i,N) cin>>A[i];
  sort(A.begin(),A.end());
  int ans;
  ans=Solve(0,N,0,0,30);
  cout<<(N-ans)<<endl;
  return 0;
}