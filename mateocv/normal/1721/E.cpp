#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

vector<ll> z_function(string& s){
	ll l=0,r=0,n=s.size();
	vector<ll> z(s.size(),0); // z[i] = max k: s[0,k) == s[i,i+k)
	fore(i,1,n){
		if(i<=r)z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
		if(i+z[i]-1>r)l=i,r=i+z[i]-1;
	}
	return z;
}

vector<ll> kmppre(string t){ // r[i]: longest border of t[0,i)
	vector<ll> r(t.size()+1);r[0]=-1;
	ll j=-1;
	fore(i,0,t.size()){
		while(j>=0&&t[i]!=t[j])j=r[j];
		r[i+1]=++j;
	}
	return r;
}

int main(){FIN;
	string s; cin>>s;
	map<string,ll> mp[11];
	auto z=z_function(s);
	fore(i,0,SZ(s)){
		if(z[i]!=SZ(s)-i)continue;
		string t;
		fore(j,0,10){
			t+=(z[i]+j<SZ(s)?s[z[i]+j]:t[z[i]+j-SZ(s)]);
			if(mp[j+1].count(t)){
				mp[j+1][t]=max(mp[j+1][t],z[i]+j+1);
			}else mp[j+1][t]=z[i]+j+1;
		}
	}
	/*
	fore(k,1,11){
		cout<<"mp"<<k<<"\n";
		for(auto i:mp[k]){
			cout<<i.fst<<" "<<i.snd<<"\n";
		}
	}
	*/
	vector<string> pr={""};
	fore(i,0,min(10ll,SZ(s)))pr.pb(pr.back()+s[i]);
	ll q; cin>>q;
	while(q--){
		string t; cin>>t;
		if(SZ(s)<=10){
			auto km=kmppre(s+t);
			fore(i,SZ(s)+1,SZ(s)+SZ(t)+1)cout<<km[i]<<" ";
		}else{
			vector<ll> res(SZ(t));
			string va="";
			fore(i,0,SZ(t)){
				va+=t[i];
				res[i]=mp[i+1][va];
			}
			fore(i,0,SZ(t)){
				va="";
				fore(j,i,SZ(t)){
					va+=t[j];
					if(va==pr[SZ(va)]){
						res[j]=max(res[j],SZ(va));
					}
				}
			}
			for(auto i:res)cout<<i<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}