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
	ll n,m; cin>>n>>m;
	vector<ll> vis(m+1);
	vector<ll> res(m+1);
	fore(i,0,m+1)res[i]=-1;
	vis[0]=1;
	fore(it,0,n){
		ll ty; cin>>ty;
		vector<ll> q(m+1);
		if(ty==1){
			ll x,y; cin>>x>>y;
			fore(i,0,m+1)q[i]=vis[i]*(y+1);
			x=(x+100000ll-1)/100000ll;
			fore(i,0,m+1){
				if(q[i]<=1)continue;
				if(i+x<=m){
					q[i+x]=max(q[i+x],q[i]-1);
				}
			}
		}else{
			ll x,y; cin>>x>>y;
			fore(i,0,m+1)q[i]=vis[i]*(y+1);
			fore(i,0,m+1){
				if(q[i]<=1)continue;
				ll ne=(i*x+100000ll-1)/100000ll;
				if(ne<=m){
					q[ne]=max(q[ne],q[i]-1);
				}
			}
		}
		fore(i,0,m+1){
			if(q[i]&&vis[i]==0){
				vis[i]=1;
				res[i]=it+1;
			}
		}
		//fore(i,0,m+1)cout<<vis[i]<<" ";
		//cout<<"\n";
		
	}
	fore(i,1,m+1)cout<<res[i]<<" ";
	cout<<"\n";
	
	
	return 0;
}