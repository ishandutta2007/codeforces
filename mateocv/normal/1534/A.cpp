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
		vector<string> v(n);
		fore(i,0,n)cin>>v[i];
		vector<string> res0(n),res1(n);
		fore(i,0,n){
			res0[i]="";
			fore(j,0,m){
				if((i+j)&1)res0[i].pb('R');
				else res0[i].pb('W');
			}
		}
		fore(i,0,n){
			res1[i]="";
			fore(j,0,m){
				if((i+j)&1)res1[i].pb('W');
				else res1[i].pb('R');
			}
		}
		pair<ll,ll> val={1,1};
		fore(i,0,n){
			fore(j,0,m){
				if(v[i][j]!='.'){
					if(res0[i][j]!=v[i][j])val.fst=0;
					if(res1[i][j]!=v[i][j])val.snd=0;
				}
			}
		}
		if(val.fst){
			cout<<"YES\n";
			fore(i,0,n){
				cout<<res0[i]<<"\n";
			}
		}else if(val.snd){
			cout<<"YES\n";
			fore(i,0,n){
				cout<<res1[i]<<"\n";
			}
		}else{
			cout<<"NO\n";
		}
	}
	
	return 0;
}