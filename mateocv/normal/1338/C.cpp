#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll solve(ll lar, ll pos, ll b){
	if(lar==1)return 0;
	if(!b){
		ll ord[4]={0,2,3,1};
		return (lar/4)*ord[pos/(lar/4)]+solve(lar/4,pos%(lar/4),0);
	}else{
		ll ord[4]={0,3,1,2};
		return (lar/4)*ord[pos/(lar/4)]+solve(lar/4,pos%(lar/4),1);
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,30){
			if((1ll<<2*i)<=n&&n<(1ll<<(2*(i+1)))){
				if(n%3==1){
					cout<<(1ll<<2*i)+(n-(1ll<<2*i))/3<<"\n";
				}else if(n%3==2){
					cout<<(1ll<<2*i+1)+solve((1ll<<2*i),(n-(1ll<<2*i))/3,0)<<"\n";
				}else{
					cout<<3*(1ll<<2*i)+solve((1ll<<2*i),(n-(1ll<<2*i))/3,1)<<"\n";
				}
				break;
			}
		}
	}
	
	return 0;
}