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

vector<pair<ll,ll>> fact(ll n){
	vector<pair<ll,ll>> res;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			res.pb({i,0});
			while(n%i==0)res[SZ(res)-1].snd++,n/=i;
		}
	}
	if(n>1)res.pb({n,1});
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,d; cin>>n>>d;
		ll c=0;
		while(n%d==0){
			n/=d;
			c++;
		}
		if(c==1){
			cout<<"NO\n";
			continue;
		}
		auto fn=fact(n);
		ll sn=0;
		for(auto i:fn)sn+=i.snd;
		if(sn>=2){
			cout<<"YES\n";
			continue;
		}
		if(c==2){
			cout<<"NO\n";
			continue;
		}
		auto fd=fact(d);
		assert(SZ(fd)>0);
		if(SZ(fd)>=2){
			cout<<"YES\n";
			continue;
		}
		if(fd[0].snd==1){
			cout<<"NO\n";
			continue;
		}
		ll br=0;
		for(auto i:fn){
			if(i.fst!=fd[0].fst)br++;
		}
		if(br){
			cout<<"YES\n";
			continue;
		}
		if(fd[0].snd+(SZ(fn)?fn[0].snd:0)<=(c-1)*(fd[0].snd-1))cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}