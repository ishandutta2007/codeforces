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

ll ask(ll x){
	cout<<"? "<<x+1<<endl;
	ll resp; cin>>resp;
	resp--;
	return resp;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> vis(n),p(n);
		fore(i,0,n){
			if(vis[i])continue;
			ll va=i;
			ll ai=ask(va);
			ll a=ai;
			va=ai;
			while(1){
				vis[va]=1;
				a=ask(i);
				p[va]=a;
				va=a;
				if(va==ai)break;
			}
		}
		cout<<"! ";
		fore(i,0,n)cout<<p[i]+1<<" ";
		cout<<endl;
	}
	
	
	return 0;
}