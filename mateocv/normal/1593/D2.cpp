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

ll c[2000006];

vector<ll> div(ll n){
	vector<ll> res;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
			res.pb(i);
			if(i*i!=n)res.pb(n/i);
		}
	}
	//cout<<n<<":\n";
	//for(auto i:res)cout<<i<<" ";
	//cout<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i],a[i]+=1000000;
		sort(ALL(a));
		map<ll,ll> mp;
		for(auto i:a)mp[i]++;
		ll br=0;
		for(auto i:mp){
			if(i.snd>=SZ(a)/2)br++;
		}
		if(br){
			cout<<"-1\n";
			continue;
		}
		//for(auto i:a)cout<<i<<" ";
		//cout<<"\n";
		ll res=1;
		vector<ll> vc;
		fore(i,0,n){
			fore(j,i+1,n){
				auto d=div(a[j]-a[i]);
				for(auto ii:d)vc.pb(ii);
			}
		}
		//for(auto i:vc)cout<<i<<" ";
		//cout<<"\n";
		sort(ALL(vc));
		for(auto i:vc){
			//cout<<i<<":\n";
			vector<ll> vis;
			for(auto j:a){
				ll r=j%i;
				c[r]++;
				vis.pb(r);
			}
			//cout<<c[0]<<" "<<c[1]<<"\n";
			for(auto j:vis){
				if(c[j]>=SZ(a)/2)res=i;
				c[j]=0;
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}