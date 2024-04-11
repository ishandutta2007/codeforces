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
	set<ll> st[2];
	fore(i,0,10){
		fore(j,i+1,10){
			fore(l,1,11){
				fore(m,0,(1ll<<l)){
					ll va=0;
					fore(ii,0,l){
						if((1ll<<ii)&m)va=10*va+i;
						else va=10*va+j;
					}
					st[1].insert(va);
					if(m==0||m==(1ll<<l)-1)st[0].insert(va);
				}
			}
		}
	}
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		cout<<*st[k-1].lower_bound(n)<<"\n";
	}
	
	return 0;
}