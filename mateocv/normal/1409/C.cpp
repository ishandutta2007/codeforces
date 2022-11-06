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
		ll n,x,y; cin>>n>>x>>y;
		ll d=y-x;
		vector<ll> res;
		ll maxi=2e9;
		fore(i,1,51){
			//cout<<i<<": ";
			vector<ll> va;
			if(d%i==0){
				//cout<<"entro ";
				fore(j,0,d/i+1){
					va.pb(x+i*j);
				}
				if(SZ(va)>n){
					continue;
					//cout<<"se fue";
				}
				ll mini=x-i,maxiv=y;
				while(mini>0&&SZ(va)<n){
					va.pb(mini);
					mini-=i;
				}
				while(SZ(va)<n){
					va.pb(maxiv+i);
					maxiv+=i;
				}
				//cout<<"quedo "<<maxiv<<" ";
				//for(auto i:va)cout<<i<<" ";
				if(maxi>maxiv){
					maxi=maxiv;
					res=va;
				}
			}
			//cout<<"\n";
		}
		for(auto i:res)cout<<i<<" "; cout<<"\n";
	}
	
	return 0;
}