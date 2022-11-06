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

const int MAXN=200005;

vector<ll> g[MAXN];

ll a[MAXN];
ll e[MAXN],izq[MAXN],der[MAXN],amb[MAXN];
vector<ll> vs;
vector<pair<ll,ll>> v;
set<ll> st;
map<ll,ll> mp;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		//cout<<"HOLAA"<<endl;
		ll n; cin>>n;
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)st.insert(a[i]);
		ll va=0;
		for(auto i:st)mp[i]=va++;
		fore(i,0,n)a[i]=mp[a[i]];
		//fore(i,0,n)cout<<a[i]<<" "; cout<<endl;
		fore(i,0,n)g[a[i]].pb(i);
		//mset(e,0);
		for(auto i:st)vs.pb(mp[i]);
		//for(auto i:vs)cout<<i<<" "; cout<<endl;
		fore(i,0,SZ(vs)-1){
			if(g[vs[i]].back()<g[vs[i+1]][0])e[i]++;
		}
		fore(i,0,SZ(vs)-1){
			ll d=g[vs[i+1]][0];
			for(auto j:g[vs[i]])if(j<d)izq[i]++;
		}
		fore(i,0,SZ(vs)-1){
			ll d=g[vs[i]].back();
			for(auto j:g[vs[i+1]])if(j>d)der[i]++;
		}
		//cout<<"HOLAA"<<endl;
		fore(i,0,SZ(vs)-1){
			ll l=0,r=0;
			ll maxi=0;
			while(l<SZ(g[vs[i]])&&r<SZ(g[vs[i+1]])){
				while(g[vs[i]][l]>g[vs[i+1]][r])r++;
				if(r==SZ(g[vs[i+1]]))break;
				maxi=max(maxi,l+1+SZ(g[vs[i+1]])-r);
				l++;
			}
			amb[i]=maxi;
		}
		//cout<<"HOLAA"<<endl;
		ll maxi=0;
		fore(i,0,SZ(vs)){
			maxi=max(maxi,SZ(g[vs[i]]));
		}
		fore(i,0,SZ(vs)-1){
			maxi=max(maxi,amb[i]);
		}
		//cout<<"HOLAA"<<endl;
		fore(i,0,SZ(vs)-2){
			maxi=max(maxi,izq[i]+der[i+1]+SZ(g[vs[i+1]]));
		}
		//cout<<"HOLAA"<<endl;
		ll ult=0;
		fore(i,0,n-1){
			if(ult==0&&e[i]==1){
				v.pb({i,i});
				ult=1;
			}else if(e[i]==1){
				v[SZ(v)-1].snd++;
			}else{
				ult=0;
			}
		}
		for(auto i:v){
			ll sum=0;
			fore(j,i.fst,i.snd+2)sum+=SZ(g[vs[j]]);
			if(i.fst>0)sum+=izq[i.fst-1];
			if(i.snd<SZ(vs)-2)sum+=der[i.snd+1];
			maxi=max(maxi,sum);
		}
		//cout<<"HOLAA"<<endl;
		cout<<n-maxi<<"\n";
		//cout<<n<<endl;
		fore(i,0,SZ(vs))g[i].clear();
		vs.clear(); v.clear();
		fore(i,0,n)e[i]=izq[i]=der[i]=amb[i]=0;
		st.clear(); mp.clear();
		//cout<<"HOLAA"<<endl;
	}
	
	return 0;
}