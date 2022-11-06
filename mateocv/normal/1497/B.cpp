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
		ll n,m; cin>>n>>m;
		ll c[m];
		mset(c,0);
		fore(i,0,n){
			ll a; cin>>a;
			c[a%m]++;
		}
		ll res=0;
		fore(i,0,m){
			if(i==0){
				res+=(c[i]>0);
			}else if(m%2==0&&i==m/2){
				res+=(c[i]>0);
			}else if(i<m-i){
				if(c[i]||c[m-i]){
					if(c[i]==c[m-i])res++;
					else res+=abs(c[i]-c[m-i]);
				}
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}