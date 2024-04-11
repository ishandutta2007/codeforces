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
 
const int MAXN=1000006;
 
vector<ll> oc[MAXN][2];
 
ll findn(ll x, ll pos, ll b){
	auto res=lower_bound(ALL(oc[x][b]),pos+1)-oc[x][b].begin();
	if(res==SZ(oc[x][b]))return 1e9;
	return oc[x][b][res];
}
 
ll a[MAXN],sump[MAXN],c[MAXN];
 
int main(){FIN;
	ll n,q; cin>>n>>q;
	fore(i,0,n)cin>>a[i];
    fore(i,1,n+1)sump[i]=sump[i-1]^a[i-1];
    fore(i,1,n+1)c[i]=c[i-1]+(a[i-1]==0);
    set<ll> st;
    fore(i,0,n+1)st.insert(sump[i]);
    map<ll,ll> mp;
    ll va=0;
    for(auto i:st)mp[i]=va++;
    fore(i,0,n+1)oc[mp[sump[i]]][i&1].pb(i);
    while(q--){
		ll l,r; cin>>l>>r; l--;
		if(c[r]-c[l]==r-l)cout<<"0\n";
		else if(sump[r]!=sump[l])cout<<"-1\n";
		else if((r-l)&1){
			cout<<"1\n";
		}else{
			if(a[l]==0||a[r-1]==0)cout<<"1\n";
			else if(findn(mp[sump[l]],l,!(l&1))<r)cout<<"2\n";
			else cout<<"-1\n";
		}
	}
	return 0;
}