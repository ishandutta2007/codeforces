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


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll x; cin>>x;
		if(x>45)cout<<"-1\n";
		else{
			ll s=x;
			string res;
			for(ll i=9;i>0;i--){
				if(s==0)break;
				if(s>=i){
					res+=('0'+i);
					s-=i;
				}else{
					res+=('0'+s);
					break;
				}
			}
			reverse(ALL(res));
			cout<<res<<"\n";
		}
	}
	
	return 0;
}