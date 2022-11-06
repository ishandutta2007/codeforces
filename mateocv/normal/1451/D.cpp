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
		ll d,k; cin>>d>>k;
		ll maxi=(d*d)/(k*k);
		fore(i,0,2ll*d+10){
			if(2ll*i*i>maxi){
				if(i*i+(i-1)*(i-1)<=maxi){
					cout<<"Ashish\n";
				}else{
					cout<<"Utkarsh\n";
				}
				break;
			}
		}
	}
	
	return 0;
}