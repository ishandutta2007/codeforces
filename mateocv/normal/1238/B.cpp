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
	ll q; cin>>q;
	while(q--){
		ll n,r; cin>>n>>r;
		ll x[n];
		fore(i,0,n)cin>>x[i];
		sort(x,x+n);
		ll res=0;
		ll va=n-1;
		ll br=0;
		fore(i,0,n){
			if(x[va]<=i*r){
				cout<<res<<"\n"; break; 
			}
			for(ll j=va;j>=-1;j--){
				if(x[j]!=x[va]){
					if(j==-1){
						cout<<res+1<<"\n"; br++; break; 
					}
					va=j; res++; break;
				}
			}
			if(br)break;
		}
	}
	
	return 0;
}