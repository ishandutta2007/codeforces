#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

ll n,a,b; // sugoku ookii tabaichou
double Rn,Ra,Rb,x; // sugoku seikaku na tabaichou

ll score(ll i){
  return min(a/i,b/(n-i));
}

int main(){
  cin>>n>>a>>b;
  Rn=n; Ra=a; Rb=b;
  x=(Ra*Rn)/(Ra+Rb);
  ll lx=floor(x), rx=ceil(x);
  ll ans=0;
  if(lx!=0){ ans=max(ans,score(lx)); }
  if(rx!=n){ ans=max(ans,score(rx)); }
  cout<<ans<<endl;
  return 0;
}