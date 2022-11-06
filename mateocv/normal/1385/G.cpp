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

vector<pair<ll,ll>> vec[200005];
ll vis[200005];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[2][n];
		ll tot[n];
		mset(tot,0);
		fore(k,0,2){
			fore(i,0,n){
				cin>>a[k][i];
				a[k][i]--;
				tot[a[k][i]]++;
			}
		}
		ll br=0;
		fore(i,0,n){
			if(tot[i]!=2){
				cout<<"-1\n";
				br++; break;
			}
		}
		if(br)continue;
		fore(i,0,n){
			vec[a[0][i]].pb({a[1][i],i});
			vec[a[1][i]].pb({a[0][i],-i-1});
		}
		vector<ll> res;
		fore(i,0,n){
			if(vis[i]||vec[i][0].fst==i)continue;
			if(vec[i][0].fst==vec[i][1].fst){
				if((vec[i][0].snd>=0&&vec[i][1].snd>=0)||(vec[i][0].snd<0&&vec[i][1].snd<0)){
					res.pb(max(vec[i][0].snd,-vec[i][0].snd-1));
				}
				vis[i]++;
				vis[vec[i][0].fst]++;
				continue;
			}
			vector<ll> v={i,vec[i][0].fst};
			vector<ll> p[2];
			p[vec[i][0].snd>=0].pb(max(vec[i][0].snd,-vec[i][0].snd-1));
			while(1){
				ll nx=vec[v.back()][0].fst^vec[v.back()][1].fst^v[SZ(v)-2];
				if(vec[v.back()][0].fst==nx){
					p[vec[v.back()][0].snd>=0].pb(max(vec[v.back()][0].snd,-vec[v.back()][0].snd-1));
				}else{
					p[vec[v.back()][1].snd>=0].pb(max(vec[v.back()][1].snd,-vec[v.back()][1].snd-1));
				}
				if(nx==v[0])break;
				v.pb(nx);
			}
			if(SZ(p[0])<=SZ(p[1])){
				for(auto i:p[0])res.pb(i);
			}else{
				for(auto i:p[1])res.pb(i);
			}
			for(auto i:v)vis[i]++;
		}
		cout<<SZ(res)<<"\n";
		for(auto i:res)cout<<i+1<<" "; cout<<"\n";
		fore(i,0,n)vec[i].clear(),vis[i]=0;
	}
	
	return 0;
}