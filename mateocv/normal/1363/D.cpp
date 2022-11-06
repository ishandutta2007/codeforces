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

ll ask(vector<ll> &v){
	cout<<"? "<<SZ(v)<<" ";
	for(auto i:v)cout<<i+1<<" ";
	cout<<endl;
	ll resp; cin>>resp;
	assert(resp!=-1);
	return resp-1;	
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vector<ll> v[k];
		fore(i,0,k){
			ll c; cin>>c;
			fore(j,0,c){
				ll lle; cin>>lle;
				v[i].pb(lle-1);
			}
		}
		vector<ll> vv;
		fore(i,0,n)vv.pb(i);
		ll maxi=ask(vv);
		ll va=0;
		fore(i,0,10){
			vv.clear();
			fore(j,0,k){
				if((j&(1ll<<i))&&((j%(1ll<<(i)))==va)){
					for(auto jj:v[j])vv.pb(jj);	
				}
			}
			if(SZ(vv)==0)continue;
			ll a=ask(vv);
			if(a==maxi){
				va=va|(1ll<<i);
			}
		}
		vv.clear();
		set<ll> st;
		fore(i,0,n)st.insert(i);
		fore(i,0,k){
			if(i==va){
				for(auto jj:v[i])st.erase(jj);
			}
		}
		for(auto i:st)vv.pb(i);
		//cout<<"HOLAA"<<endl;
		ll otr;
		if(SZ(vv)!=0)otr=ask(vv);
		else otr=maxi;
		cout<<"! ";
		fore(i,0,k){
			if(i!=va)cout<<maxi+1<<" ";
			else cout<<otr+1<<" ";
		}
		cout<<endl;
		string ver; cin>>ver;
		if(ver!="Correct"){
			exit(0);
		}
	}
	
	return 0;
}