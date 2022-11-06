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

vector<ll> oc[100005];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll> c(n+2);
		for(auto i:a)c[i]++;
		auto sump=c;
		fore(i,1,SZ(sump))sump[i]+=sump[i-1];
		ll k=-1;
		fore(i,0,n+1){
			if(n-sump[i]==i){
				k=i;
				break;
			}
		}
		assert(k!=-1);
		vector<ll> ex(n+2,0);
		for(auto i:a)ex[i]=1;
		vector<ll> res;
		ll va=0;
		if(!ex[0])va=n+1;
		fore(i,0,n+2)oc[i].clear();
		fore(i,0,n)oc[a[i]].pb(i+1);
		while(SZ(res)<n){
			ll ul=-1;
			for(auto i:oc[va]){
				if(ex[i])ul=i;
			}
			for(auto i:oc[va])if(i!=ul)res.pb(i);
			res.pb(ul);
			va=ul;
		}
		res.pop_back();
		cout<<k<<"\n";
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}
	
	return 0;
}