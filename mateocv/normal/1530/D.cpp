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

vector<ll> g[200005];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)g[i].clear();
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		fore(i,0,n)g[a[i]].pb(i);
		vector<ll> res(n,-1);
		set<ll> st;
		fore(i,0,n)st.insert(i);
		fore(i,0,n){
			if(SZ(g[i])){
				res[g[i][0]]=i;
				st.erase(i);
			}
		}
		//for(auto i:res)cout<<i<<" ";
		//cout<<"\n";
		vector<ll> f,fr;
		fore(i,0,n){
			if(res[i]==-1)f.pb(i);
		}
		fore(i,0,SZ(f)){
			if(st.count(f[i])){
				fr.pb(f[i]);
				st.erase(f[i]);
			}else{
				fr.pb(-1);
			}
		}
		fore(i,0,SZ(fr)){
			if(fr[i]==-1){
				ll b=*st.begin();
				fr[i]=b;
				st.erase(b);
			}
		}
		fore(i,0,SZ(f)){
			res[f[i]]=fr[(i+1)%SZ(f)];
		}
		//for(auto i:res)cout<<i<<" ";
		//cout<<"\n";
		vector<ll> rep;
		fore(i,0,n){
			if(res[i]==i)rep.pb(i);
		}
		assert(SZ(rep)<=1);
		if(SZ(rep)==1){
			ll el=rep[0];
			assert(SZ(g[a[el]])==2);
			ll ot=g[a[el]][0];
			swap(res[ot],res[el]);
		}
		ll tot=0;
		fore(i,0,n){
			if(res[i]==a[i])tot++;
		}
		cout<<tot<<"\n";
		fore(i,0,n)cout<<res[i]+1<<" ";
		cout<<"\n";
	}
	
	return 0;
}