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
		ll n; cin>>n;
		vector<ll> v(n);
		fore(i,0,n){
			ll mk=0;
			fore(j,0,5){
				ll x; cin>>x;
				mk<<=1;
				mk+=x;
			}
			v[i]=mk;
		}
		ll br=0;
		fore(ii,0,5){
			fore(jj,ii+1,5){
				ll c[4];
				mset(c,0);
				vector<ll> vm={0,(1ll<<ii),(1ll<<jj),(1ll<<ii)+(1ll<<jj)};
				fore(i,0,n){
					fore(j,0,SZ(vm)){
						if((v[i]&((1ll<<ii)+(1ll<<jj)))==vm[j])c[j]++;
					}
				}
				if(c[0]==0&&c[1]<=n/2&&c[2]<=n/2)br++;
			}
		}
		if(br)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}