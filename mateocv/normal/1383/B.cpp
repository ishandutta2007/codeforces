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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll x=0;
		fore(i,0,n)x^=a[i];
		if(x==0){
			cout<<"DRAW\n";
			continue;
		}
		ll maxi=0;
		fore(i,0,30){
			if((1ll<<i)&x){
				maxi=max(maxi,i);
			}
		}
		ll cant[2]={0,0};
		fore(i,0,n){
			if((1ll<<maxi)&a[i])cant[1]++;
			else cant[0]++;
		}
		if(cant[0]&1){
			cout<<"WIN\n";
		}else{
			if(cant[1]%4==1){
				cout<<"WIN\n";
			}else{
				cout<<"LOSE\n";
			}
		}
	}
	
	return 0;
}