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

set<pair<ll,ll>> st;

ll getv(ll n, ll k){
	ll p=n/k,c=(n+k-1)/k;
	return (n%k)*c*c+(k-(n%k))*p*p;
}

ll par[100005],val[100005];

int main(){FIN;
	ll n,k; cin>>n>>k;
	fore(i,0,n)par[i]=1;
	fore(i,0,n)cin>>val[i];
	ll res=0;
	fore(i,0,n){
		res+=getv(val[i],1);
		if(val[i]>1){
			st.insert({-getv(val[i],1)+getv(val[i],2),i});
		}
	}
	//cout<<res<<"\n";
	//for(auto i:st)cout<<i.fst<<" "<<i.snd<<"\n";
	while(n<k){
		assert(SZ(st));
		auto b=*st.begin();
		res+=b.fst;
		st.erase(b);
		par[b.snd]++;
		if(par[b.snd]<val[b.snd]){
			st.insert({-getv(val[b.snd],par[b.snd])+getv(val[b.snd],par[b.snd]+1),b.snd});
		}
		n++;
	}
	cout<<res<<"\n";
	
	return 0;
}