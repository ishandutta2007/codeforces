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
		ll n,dab,dbc,dca; cin>>n>>dab>>dbc>>dca;
		ll s=dab+dbc+dca,maxi=max({dab,dbc,dca});
		if((s&1)||s/2>n-1||maxi>s-maxi){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		ll st=0;
		while(dab!=maxi){
			swap(dab,dbc);
			swap(dbc,dca);
			st++;
		}
		if(dab==dbc+dca){
			vector<ll> v(n,-1);
			v[0]=st+1;
			v[dab]=(st+1)%3+1;
			v[dca]=(st+2)%3+1;
			ll va=4;
			fore(i,0,n)if(v[i]==-1)v[i]=va++;
			fore(i,0,n-1){
				cout<<v[i]<<" "<<v[i+1]<<"\n";
			}
		}else{
			ll va=5;
			ll ul=4;
			fore(i,0,s/2-dbc-1)cout<<ul<<" "<<va++<<"\n",ul=va-1;
			cout<<ul<<" "<<st+1<<"\n";
			
			ul=4;
			fore(i,0,s/2-dca-1)cout<<ul<<" "<<va++<<"\n",ul=va-1;
			cout<<ul<<" "<<(st+1)%3+1<<"\n";
			
			ul=4;
			fore(i,0,s/2-dab-1)cout<<ul<<" "<<va++<<"\n",ul=va-1;
			cout<<ul<<" "<<(st+2)%3+1<<"\n";
			
			while(va<=n){
				cout<<va-1<<" "<<va<<"\n";
				va++;
			}
		}
	}
	
	return 0;
}