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

ll val(ll x, ll y, ll n, ll m){
	return 0<=x&&x<n&&0<=y&&y<m;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll> p={0,1,2,3};
		ll maxi=0;
		vector<string> res(n,string(m,'0'));
		vector<pair<ll,ll>> dir={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,-1},{-1,1}};
		do{
			vector<string> va(n,string(m,'0'));
			for(auto i:p){
				ll tot=0;
				if(i==0){
					fore(ii,0,m){
						ll br=0;
						for(auto id:dir){
							ll x=id.fst,y=ii+id.snd;
							if(val(x,y,n,m)&&va[x][y]=='1')br++;
						}
						if(!br)va[0][ii]='1',tot++;
					}
				}
				if(i==1){
					fore(ii,0,m){
						ll br=0;
						for(auto id:dir){
							ll x=n-1+id.fst,y=ii+id.snd;
							if(val(x,y,n,m)&&va[x][y]=='1')br++;
						}
						if(!br)va[n-1][ii]='1',tot++;
					}
				}
				if(i==2){
					fore(ii,0,n){
						ll br=0;
						for(auto id:dir){
							ll x=ii+id.fst,y=id.snd;
							if(val(x,y,n,m)&&va[x][y]=='1')br++;
						}
						if(!br)va[ii][0]='1',tot++;
					}
				}
				if(i==3){
					fore(ii,0,n){
						ll br=0;
						for(auto id:dir){
							ll x=ii+id.fst,y=m-1+id.snd;
							if(val(x,y,n,m)&&va[x][y]=='1')br++;
						}
						if(!br)va[ii][m-1]='1',tot++;
					}
				}
				if(tot>maxi){
					tot=maxi;
					res=va;
				}
			}
		}while(next_permutation(ALL(p)));
		for(auto i:res)cout<<i<<"\n";
	}
	
	return 0;
}