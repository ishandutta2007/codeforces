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

ll INF=9e18;

#define oper min
const int K=19;
ll st[2][K][1<<K];
void st_init(vector<ll> a, ll b){
	fore(i,0,SZ(a))st[b][0][i]=a[i];
	fore(k,1,K)fore(i,0,SZ(a)-(1<<k)+1)
		st[b][k][i]=oper(st[b][k-1][i],st[b][k-1][i+(1<<(k-1))]);
}
ll st_query(int s, int e, ll b){
	if(s==e)return INF;
	int k=31-__builtin_clz(e-s);
	return oper(st[b][k][s],st[b][k][e-(1<<k)]);
}

vector<ll> comp(vector<ll> v){
	auto el=v;
	sort(ALL(el));
	el.erase(unique(ALL(el)),el.end());
	fore(i,0,SZ(v))v[i]=lower_bound(ALL(el),v[i])-el.begin();
	return v;
}

vector<ll> oc[300005];

ll cont(ll val, ll l, ll r){
	return lower_bound(ALL(oc[val]),r)-lower_bound(ALL(oc[val]),l);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll> sump={0};
		ll sg=-1;
		for(auto i:a)sump.pb(sump.back()+i*sg),sg=-sg;
		//for(auto i:sump)cout<<i<<" "; cout<<"\n";
		vector<ll> v[2];
		fore(k,0,2)v[k].resize(n,INF);
		fore(i,0,n){
			if(i&1){
				v[1][i]=sump[i+1];
			}else{
				v[0][i]=-sump[i+1];
			}
		}
		/*
		fore(k,0,2){
			for(auto i:v[k])cout<<i<<" "; cout<<"\n";
		}
		*/
		fore(k,0,2)st_init(v[k],k);
		auto c=comp(sump);
		//for(auto i:c)cout<<i<<" "; cout<<"\n";
		fore(i,0,SZ(c))oc[i].clear();
		fore(i,0,SZ(c))oc[c[i]].pb(i);
		ll res=0;
		fore(i,0,n){
			ll l=i,r=n-1;
			while(l<=r){
				ll m=(l+r)/2;
				ll mini=INF;
				mini=min(mini,st_query(i,m+1,0)+sump[i]);
				mini=min(mini,st_query(i,m+1,1)-sump[i]);
				if(mini>=0)l=m+1;
				else r=m-1;
			}
			//cout<<i<<" "<<l<<"\n";
			res+=cont(c[i],i+1,l+1);
			//cout<<res<<"\n";
		}
		cout<<res<<"\n";
	}
	
	return 0;
}