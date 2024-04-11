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
		ll va=0,tot=0;
		fore(i,1,x+1){
			va+=i;
			tot++;
			if(va>=x)break;
		}
		if(va==x||va>=x+2)cout<<tot<<"\n";
		else cout<<tot+1<<"\n";
	}
	
	return 0;
}