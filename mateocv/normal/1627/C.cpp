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
		vector<pair<pair<ll,ll>,ll>> ed;
		map<pair<ll,ll>,ll> mp;
		vector<ll> c(n);
		fore(i,0,n-1){
			ll x,y; cin>>x>>y; x--; y--;
			ed.pb({{x,y},i});
			c[x]++;
			c[y]++;
			mp[{min(x,y),max(x,y)}]=i;
		}
		ll br=0;
		fore(i,0,n){
			if(c[i]>=3)br++;
		}
		if(br){
			cout<<"-1\n"; 
			continue;
		}
		ll va=-1;
		fore(i,0,n){
			if(c[i]==1)va=i;
		}
		vector<pair<ll,ll>> vec(n,{-1,-1});
		for(auto i:ed){
			ll x=i.fst.fst,y=i.fst.snd;
			if(vec[x].fst==-1)vec[x].fst=y;
			else vec[x].snd=y;
			swap(x,y);
			if(vec[x].fst==-1)vec[x].fst=y;
			else vec[x].snd=y;
		}
		vector<ll> w={va};
		while(va!=-1){
			va=vec[va].fst^vec[va].snd^(SZ(w)==1?-1:w[SZ(w)-2]);
			w.pb(va);
		}
		vector<ll> res(n-1);
		fore(i,0,n-1){
			res[mp[{min(w[i],w[i+1]),max(w[i],w[i+1])}]]=2+(i&1);
		}
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}
	
	return 0;
}