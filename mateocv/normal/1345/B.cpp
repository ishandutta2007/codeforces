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
		ll res=0;
		while(n>1){
			fore(i,0,1000000){
				if((3*i*i+i)/2>n){
					res++;
					n-=(3*(i-1)*(i-1)+i-1)/2;
					break;
				}
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}