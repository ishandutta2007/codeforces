#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n; cin>>n;
	vector<ll> v[2][30];
	char c;
	fore(k,0,2){
		fore(i,0,n){
			cin>>c;
			if(c=='?'){
				v[k][26].pb(i+1);
			}else{
				v[k][0+c-'a'].pb(i+1);
			}
		}
	}
	ll res=0;
	vector<pair<ll,ll>> par;
	fore(i,0,26){
		ll m=min(SZ(v[0][i]),SZ(v[1][i]));
		res+=m;
		while(m--){
			par.pb({v[0][i].back(),v[1][i].back()});
			v[0][i].pop_back(); v[1][i].pop_back();
		}
	}
/*	ll sum[2]={0,0};
	fore(k,0,2){
		fore(i,0,26){
			sum[k]+=SZ(v[k][i]);
		}
	}*/
	vector<ll> sob[2];
	fore(k,0,2){
		fore(i,0,26){
			while(SZ(v[k][i])>0){
				sob[k].pb(v[k][i].back());
				//cout<<"Metiendo una "<<char('a'+i)<<" de la posicion "<<v[k][i].back()<<"\n";
				v[k][i].pop_back();
			}
		}
	}
	
//	fore(i,0,SZ(sob[1]))cout<<sob[1][i]<<" ";
	fore(k,0,2){
		ll m=min(SZ(v[k][26]),SZ(sob[1-k]));
		res+=m;
		//cout<<m<<"\n";
		while(m--){
			if(k==0){
				par.pb({v[k][26].back(),sob[1-k].back()});
			}else{
				par.pb({sob[1-k].back(),v[k][26].back()});
			}
			
			//cout<<"Metiendo una "<<char()<<" de la posicion "<<v[k][i].back()<<"\n";
			v[k][26].pop_back(); sob[1-k].pop_back();
		}
	}
	
	ll m=min(SZ(v[0][26]),SZ(v[1][26]));
	res+=m;
//	cout<<m<<"\n";
	while(m--){
		par.pb({v[0][26].back(),v[1][26].back()});
		v[0][26].pop_back(); v[1][26].pop_back(); 
	}
	
	cout<<res<<"\n";
	fore(i,0,res){
		cout<<par[i].fst<<" "<<par[i].snd<<"\n";
	}
	
	return 0;
}