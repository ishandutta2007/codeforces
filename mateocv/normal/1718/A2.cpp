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

ll dp[100005],ne[100005];

ll n;

vector<ll> oc[100005];

ll f(ll x){
	ll &res=dp[x];
	if(res>=0)return res;
	if(x==n)return res=0;
	res=f(x+1)+1;
	if(ne[x]!=-1)res=min(res,f(ne[x])+ne[x]-x-1);
	return res;
}

void comp(vector<ll> &v){
	vector<ll> el=v;
	sort(ALL(el));
	el.erase(unique(ALL(el)), el.end());
	fore(i,0,SZ(v))v[i]=lower_bound(ALL(el),v[i])-el.begin();
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll> xp={0};
		fore(i,0,n)xp.pb(xp.back()^a[i]);
		comp(xp);
		//for(auto i:xp)cout<<i<<" "; cout<<"\n";
		fore(i,0,SZ(xp))oc[i].clear();
		fore(i,0,SZ(xp))oc[xp[i]].pb(i);
		fore(i,0,n+1){
			ll pos=lower_bound(ALL(oc[xp[i]]),i+1)-oc[xp[i]].begin();
			if(pos==SZ(oc[xp[i]]))ne[i]=-1;
			else ne[i]=oc[xp[i]][pos];
		}
		//fore(i,0,n+1)cout<<ne[i]<<" "; cout<<"\n";
		fore(i,0,SZ(a)+2)dp[i]=-1;
		cout<<f(0)<<"\n";
	}
	
	return 0;
}