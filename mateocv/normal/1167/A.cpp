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

const ll MOD=998244353;

int main(){FIN;
  ll t; cin>>t;
  while(t--){
    ll n; cin>>n;
    string s; cin>>s;
    if(n<11){
      cout<<"NO\n"; continue;
    }
    ll br=0;
    fore(i,0,n-10){
      if(s[i]=='8'){
        cout<<"YES\n"; br++; break;
      }
    }
    if(!br)cout<<"NO\n";
  }
	return 0;
}