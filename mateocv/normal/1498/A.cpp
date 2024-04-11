#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll sumd(ll n){
	//cout<<n<<" ";
	ll res=0;
	while(n>0){
		res+=(n%10);
		n/=10;
	}
	//cout<<res<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,10){
			if(__gcd(n+i,sumd(n+i))>1){
				cout<<n+i<<"\n";
				break;
			}
		}
	}
	
	return 0;
}