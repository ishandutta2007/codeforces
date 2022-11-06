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
	ll n; cin>>n;
	ll t[n][n];
	fore(i,0,n){
		fore(j,0,n){
			if(i&1)t[i][j]=(1ll<<(n+n-i-j));
			else t[i][j]=0;
		}
	}
	fore(i,0,n){
		fore(j,0,n){
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}
	ll q; cin>>q;
	while(q--){
		ll k; cin>>k;
		vector<pair<ll,ll>> res={{0,0}};
		k-=t[0][0];
		while(SZ(res)<2*n-1){
			auto b=res.back();
			if(b.fst==n-1){
				res.pb({b.fst,b.snd+1});
				k-=t[b.fst][b.snd+1];
			}else if(b.snd==n-1){
				res.pb({b.fst+1,b.snd});
				k-=t[b.fst+1][b.snd];
			}else{
				if(t[b.fst][b.snd+1]>=t[b.fst+1][b.snd]){
					if(k>=t[b.fst][b.snd+1]){
						res.pb({b.fst,b.snd+1});
						k-=t[b.fst][b.snd+1];
					}else{
						res.pb({b.fst+1,b.snd});
						k-=t[b.fst+1][b.snd];
					}
				}else{
					if(k>=t[b.fst+1][b.snd]){
						res.pb({b.fst+1,b.snd});
						k-=t[b.fst+1][b.snd];
					}else{
						res.pb({b.fst,b.snd+1});
						k-=t[b.fst][b.snd+1];
					}
				}
				
			}
		}
		assert(k==0);
		for(auto i:res)cout<<i.fst+1<<" "<<i.snd+1<<endl;
	
	}
	return 0;
}