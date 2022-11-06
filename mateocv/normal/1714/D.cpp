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
		string s; cin>>s;
		ll n; cin>>n;
		vector<string> a(n);
		fore(i,0,n)cin>>a[i];
		vector<pair<ll,pair<ll,ll>>> vm(SZ(s));
		fore(i,0,SZ(s))vm[i]={i,{-1,-1}};
		fore(i,0,SZ(s)){
			ll va=0;
			for(auto j:a){
				if(i+SZ(j)<=SZ(s)&&s.substr(i,SZ(j))==j){
					fore(ii,i,i+SZ(j)){
						vm[ii]=max(vm[ii],{i+SZ(j),{i,va}});
					}
				}
				va++;
			}
		}
		ll br=0;
		vector<pair<ll,ll>> res;
		ll pos=0;
		while(pos<SZ(s)){
			auto npos=vm[pos];
			if(npos.fst==pos){
				br++; break;
			}
			res.pb(npos.snd);
			pos=npos.fst;
		}
		if(br)cout<<"-1\n";
		else{
			cout<<SZ(res)<<"\n";
			for(auto i:res)cout<<i.snd+1<<" "<<i.fst+1<<"\n";
		}
	}
	
	return 0;
}