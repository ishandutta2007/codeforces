#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
  while(t--){
    ll n,k; cin>>n>>k;
    if(k==1)cout<<n<<"\n";
    else{
      ll res=0;
      while(n>0){
        if(n%k==0)n/=k,res++;
        else res+=n%k,n-=n%k;
      }
      cout<<res<<"\n";
    }
  }
	
	return 0;
}